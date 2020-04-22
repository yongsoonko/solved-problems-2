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

int N, ans = 1e9;
int W[11][11], A[11];

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

  for (int i = 0; i < N; i++) {
    A[i] = i;
    for (int j = 0; j < N; j++)
      cin >> W[i][j];
  }

  do {
    int sum = 0, flag = 1;
    for (int i = 1; i < N; i++) {
      if (W[A[i - 1]][A[i]])
        sum += W[A[i - 1]][A[i]];
      else {
        flag = 0;
        break;
      }
    }
    if (flag && W[A[N - 1]][A[0]]) {
      ans = min(ans, sum + W[A[N - 1]][A[0]]);
    }
  } while (next_permutation());

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}