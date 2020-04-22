#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int N;
int A[1001];

bool next_permutation() {
  int pv = 0;
  for (int i = 1; i < N; i++)
    if (A[i - 1] < A[i])
      pv = i;

  if (not pv)
    return 0;

  for (int i = N - 1; i >= pv; i--)
    if (A[i] > A[pv - 1]) {
      swap(A[i], A[pv - 1]);
      break;
    }

  reverse(A + pv, A + N);
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  sort(A, A + N);

  do {
    for (int i = 0; i < N; i++)
      cout << A[i] << ' ';
    cout << '\n';
  } while (next_permutation());

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}