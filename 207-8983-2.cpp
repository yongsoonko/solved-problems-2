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

  // 동물 p, 사대 포인터 aPos
  int p = 0;
  while (p < N) {
    if (P[p].j <= L) {
      int *aPos;
      if ((aPos = lower_bound(A, A + M, P[p].i)) == A + M)
        aPos--;
      if ((abs(P[p].i - *aPos) + P[p].j <= L) ||
          (aPos > A && abs(P[p].i - *(aPos - 1)) + P[p].j <= L))
        ans++;
    }
    p++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}