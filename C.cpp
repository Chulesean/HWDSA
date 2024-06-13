#include <algorithm>
#include <iostream>
#include <vector>

void customSort(std::vector<int>& arr) { std::sort(arr.begin(), arr.end()); }

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  customSort(arr);

  for (int num : arr) {
    std::cout << num << " ";
  }

  return 0;
}