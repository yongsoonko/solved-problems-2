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

int A[1000001], B[1000001], C[2000002];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < M; i++)
    cin >> B[i];

  int i = 0, j = 0, k = 0;
  while (i < N && j < M) {
    if (A[i] < B[j])
      C[k++] = A[i++];
    else
      C[k++] = B[j++];
  }

  while (i < N)
    C[k++] = A[i++];

  while (j < M)
    C[k++] = B[j++];

  for (int i = 0; i < k; i++)
    cout << C[i] << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}