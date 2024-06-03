#include <iostream>
#include <vector>

int getByte(long long num, int bytePos) { return (num >> (8 * bytePos)) & 255; }

void radixSortLSD(std::vector<long long>& arr) {
  const int NUM_BYTES = 8;

  for (int bytePos = 0; bytePos < NUM_BYTES; ++bytePos) {
    std::vector<std::vector<long long>> buckets(256);

    for (long long num : arr) {
      int byteValue = getByte(num, bytePos);
      buckets[byteValue].push_back(num);
    }

    int index = 0;
    for (const auto& bucket : buckets) {
      for (long long num : bucket) {
        arr[index++] = num;
      }
    }
  }
}

int main() {
  int N;
  std::cin >> N;

  std::vector<long long> arr(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  radixSortLSD(arr);

  for (long long num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
