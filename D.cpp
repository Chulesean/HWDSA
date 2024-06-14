#include <climits>
#include <deque>
#include <iostream>
#include <string>

class MagicHat {
 private:
  std::deque<int> queue;
  std::deque<int> minQueue;

 public:
  std::string enqueue(int n) {
    queue.push_back(n);
    while (!minQueue.empty() && minQueue.back() > n) {
      minQueue.pop_back();
    }
    minQueue.push_back(n);
    return "ok";
  }

  std::string dequeue() {
    if (queue.empty()) {
      return "error";
    }
    int removed = queue.front();
    queue.pop_front();
    if (removed == minQueue.front()) {
      minQueue.pop_front();
    }
    return std::to_string(removed);
  }

  std::string front() {
    if (queue.empty()) {
      return "error";
    }
    return std::to_string(queue.front());
  }

  std::string size() { return std::to_string(queue.size()); }

  std::string clear() {
    queue.clear();
    minQueue.clear();
    return "ok";
  }

  std::string min() {
    if (minQueue.empty()) {
      return "error";
    }
    return std::to_string(minQueue.front());
  }
};

int main() {
  int M;
  std::cin >> M;
  std::cin.ignore();

  MagicHat hat;
  std::string command;
  std::deque<std::string> results;

  for (int i = 0; i < M; ++i) {
    std::getline(std::cin, command);
    if (command.substr(0, 7) == "enqueue") {
      int n = std::stoi(command.substr(8));
      results.push_back(hat.enqueue(n));
    } else if (command == "dequeue") {
      results.push_back(hat.dequeue());
    } else if (command == "front") {
      results.push_back(hat.front());
    } else if (command == "size") {
      results.push_back(hat.size());
    } else if (command == "clear") {
      results.push_back(hat.clear());
    } else if (command == "min") {
      results.push_back(hat.min());
    }
  }

  for (const auto& result : results) {
    std::cout << result << std::endl;
  }

  return 0;
}
