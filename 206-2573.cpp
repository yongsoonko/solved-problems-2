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
};

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int N, M, ans;
int A[301][301], B[301][301];
bool chk[301][301];
vector<Pos> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      if (A[i][j])
        P.push_back({i, j});
    }

  while (P.size()) {
    chk[P[0].i][P[0].j] = 1;
    queue<Pos> Q;
    Q.push({P[0].i, P[0].j});

    int cnt = 0;
    vector<Pos> v;
    while (Q.size()) {
      int ci = Q.front().i, cj = Q.front().j;
      Q.pop();
      cnt++;

      int wCnt = 0;
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
          if (!chk[ni][nj] && A[ni][nj]) {
            chk[ni][nj] = 1;
            Q.push({ni, nj});
          } else if (A[ni][nj] == 0)
            wCnt++;
        }
      }
      B[ci][cj] = max(A[ci][cj] - wCnt, 0);
      if (B[ci][cj])
        v.push_back({ci, cj});
    }
    if (cnt < P.size()) {
      cout << ans;
      return 0;
    }
    ans++;
    for (Pos p : P) {
      chk[p.i][p.j] = 0;
      A[p.i][p.j] = B[p.i][p.j];
    }
    P.swap(v);
  }

  cout << 0;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}