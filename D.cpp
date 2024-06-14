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
  int currentMin = INT_MAX;
  while (M--) {
    string command;
    cin >> command;

    if (command == "enqueue") {
      int n;
      cin >> n;
      intelligenceQueue.push(n);
      cout << "ok" << endl;
      currentMin = min(currentMin, n);
    } else if (command == "dequeue") {
      if (!intelligenceQueue.empty()) {
        cout << intelligenceQueue.front() << endl;
        if (intelligenceQueue.front() == currentMin) {
          intelligenceQueue.pop();
          if (intelligenceQueue.empty()) {
            currentMin = INT_MAX;
          } else {
            currentMin = INT_MAX;
            queue<int> tempQueue = intelligenceQueue;
            while (!tempQueue.empty()) {
              currentMin = min(currentMin, tempQueue.front());
              tempQueue.pop();
            }
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
      currentMin = INT_MAX;
    } else if (command == "min") {
      if (!intelligenceQueue.empty()) {
        cout << currentMin << endl;
      } else {
        cout << "error" << endl;
      }
    }
  }

  return 0;
}
