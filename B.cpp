#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void generateSequence(vector<int>& sequence, int n, int A0, int A1) {
  sequence[0] = A0;
  sequence[1] = A1;

  for (int i = 2; i < n; ++i)
    sequence[i] =
        (123 * sequence[i - 1] + 45 * sequence[i - 2]) % (10000000 + 4321);
}

int main() {
  int n, k, A0, A1;
  cin >> n >> k >> A0 >> A1;

  vector<int> sequence(n);
  generateSequence(sequence, n, A0, A1);

  nth_element(sequence.begin(), sequence.begin() + k - 1, sequence.end());

  cout << sequence[k - 1] << endl;

  return 0;
}
