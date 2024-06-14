#include <climits>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int M;
  cin >> M;

  queue<int> intelligenceQueue;
  int minIntelligence = INT_MAX;

  while (M--) {
    string command;
    cin >> command;

    if (command == "enqueue") {
      int n;
      cin >> n;
      intelligenceQueue.push(n);
      cout << "ok" << endl;
      minIntelligence = min(minIntelligence, n);
    } else if (command == "dequeue") {
      if (!intelligenceQueue.empty()) {
        cout << intelligenceQueue.front() << endl;
        if (intelligenceQueue.front() == minIntelligence) {
          intelligenceQueue.pop();
          minIntelligence = INT_MAX;
          queue<int> tempQueue = intelligenceQueue;
          while (!tempQueue.empty()) {
            minIntelligence = min(minIntelligence, tempQueue.front());
            tempQueue.pop();
          }
        } else {
          intelligenceQueue.pop();
        }
      } else {
        cout << "error" << endl;
      }
    } else if (command == "front") {
      if (!intelligenceQueue.empty()) {
        cout << intelligenceQueue.front() << endl;
      } else {
        cout << "error" << endl;
      }
    } else if (command == "size") {
      cout << intelligenceQueue.size() << endl;
    } else if (command == "clear") {
      while (!intelligenceQueue.empty()) {
        intelligenceQueue.pop();
      }
      cout << "ok" << endl;
      minIntelligence = INT_MAX;
    } else if (command == "min") {
      if (!intelligenceQueue.empty()) {
        cout << minIntelligence << endl;
      } else {
        cout << "error" << endl;
      }
    }
  }

  return 0;
}
