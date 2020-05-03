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
  int k;
};

int di[6] = {1, 0, -1, 0, 0, 0},
    dj[6] = {0, 1, 0, -1, 0, 0},
    dk[6] = {0, 0, 0, 0, 1, -1};
int L, R, C, ans;
Pos E;
string map[31][31];
bool chk[31][31][31];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
  start:
    cin >> L >> R >> C;
    if (L == 0)
      break;

    queue<Pos> Q;

    ans = 0;
    fill(&chk[0][0][0], &chk[L - 1][R - 1][C], 0);
    for (int k = 0; k < L; k++)
      for (int i = 0; i < R; i++) {
        cin >> map[k][i];
        for (int j = 0; j < C; j++)
          if (map[k][i][j] == 'S') {
            chk[k][i][j] = 1;
            map[k][i][j] = '.';
            Q.push({i, j, k});
          } else if (map[k][i][j] == 'E')
            E = {i, j, k};
      }

    while (Q.size()) {
      int sz = Q.size();
      while (sz--) {
        int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
        Q.pop();
        for (int m = 0; m < 6; m++) {
          int ni = ci + di[m], nj = cj + dj[m], nk = ck + dk[m];
          if (ni >= 0 && ni < R && nj >= 0 && nj < C && nk >= 0 && nk < L &&
              !chk[nk][ni][nj] && map[nk][ni][nj] != '#') {
            chk[nk][ni][nj] = 1;
            Q.push({ni, nj, nk});
          }
        }
      }
      ans++;
      if (chk[E.k][E.i][E.j]) {
        cout << "Escaped in " << ans << " minute(s).\n";
        goto start;
      }
    }
    cout << "Trapped!\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}