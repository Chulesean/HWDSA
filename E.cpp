#include <climits>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> cars;

  int minAcceleration = INT_MAX;

  while (n--) {
    char op;
    int value;
    cin >> op >> value;

    if (op == '+') {
      int newAcceleration = (value + minAcceleration) % 1000000000;
      cars.insert(newAcceleration);
      minAcceleration = *cars.begin();
    } else if (op == '?') {
      auto it = cars.lower_bound(value);
      if (it == cars.end()) {
        cout << -1 << endl;
      } else {
        cout << *it << endl;
      }
    }
  }

  return 0;
}
