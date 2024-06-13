#include <iostream>
using namespace std;

bool BinarySearch(const int* first, const int* last, int target) {
  while (first <= last) {
    const int* mid = first + (last - first) / 2;
    if (*mid == target)
      return true;
    else if (*mid < target)
      first = mid + 1;
    else
      last = mid - 1;
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  int* arr = new int[N];
  for (int i = 0; i < N; ++i) cin >> arr[i];

  int Q;
  cin >> Q;

  while (Q > 0) {
    int i, j, t;
    cin >> i >> j >> t;
    Q--;

    if (BinarySearch(arr + i, arr + j - 1, t))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  delete[] arr;
  return 0;
}
