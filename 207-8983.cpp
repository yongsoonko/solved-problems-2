#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
  bool operator<(const Pos &p) const {
    return i == p.i ? j < p.j : i < p.i;
  }
};

int M, N, ans;
int L;
int A[100001];
Pos P[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N >> L;
  for (int i = 0; i < M; i++)
    cin >> A[i];

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    P[i] = {a, b};
  }

  sort(A, A + M);
  sort(P, P + N);

  // 동물 p, 사대 q
  int p = 0, q = 0;
  while (p < N) {
    if (P[p].i <= A[q] || q == M - 1) {
      if ((abs(P[p].i - A[q]) + P[p].j <= L) ||
          (q >= 1 && abs(P[p].i - A[q - 1]) + P[p].j <= L))
        ans++;
      p++;
    } else
      q++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}