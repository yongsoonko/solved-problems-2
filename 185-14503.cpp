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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int map[51][51];
int chk[51][51];
int N, M, r, c, d, ans = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> r >> c >> d;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  int i, nd, nr, nc;
  chk[r][c] = 1;
  while (1) {
    for (i = 3; i >= 0; i--) {
      nd = (d + i) % 4;
      nr = r + di[nd], nc = c + dj[nd];
      if (map[nr][nc] == 0 && !chk[nr][nc]) {
        chk[nr][nc] = 1;
        r = nr, c = nc, d = nd;
        ans++;
        break;
      }
    }
    if (i == -1) {
      nr = r - di[d], nc = c - dj[d];
      if (map[nr][nc] == 1)
        break;
      else
        r = nr, c = nc;
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}