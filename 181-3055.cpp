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
int R, C, ans;
Pos D;
string map[51];
int chk[51][51], chk2[51][51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C;
  queue<Pos> Q, Q2;

  for (int i = 0; i < R; i++) {
    cin >> map[i];
    for (int j = 0; j < C; j++) {
      if (map[i][j] == 'S') {
        chk[i][j] = 1;
        Q.push({i, j});
        map[i][j] = '.';
      } else if (map[i][j] == 'D')
        D = {i, j};
      else if (map[i][j] == '*') {
        chk[i][j] = 1;
        Q2.push({i, j});
        map[i][j] = '.';
      }
    }
  }

  while (Q.size()) {
    int sz = Q2.size();
    while (sz--) {
      int ci = Q2.front().i, cj = Q2.front().j;
      Q2.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < R && nj >= 0 && nj < C &&
            !chk2[ni][nj] && map[ni][nj] == '.') {
          chk2[ni][nj] = 1;
          Q2.push({ni, nj});
        }
      }
    }
    sz = Q.size();
    while (sz--) {
      int ci = Q.front().i, cj = Q.front().j;
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < R && nj >= 0 && nj < C &&
            !chk2[ni][nj] && !chk[ni][nj] &&
            (map[ni][nj] == '.' || map[ni][nj] == 'D')) {
          chk[ni][nj] = 1;
          Q.push({ni, nj});
        }
      }
    }
    ans++;
    if (chk[D.i][D.j])
      break;
  }

  if (chk[D.i][D.j])
    cout << ans;
  else
    cout << "KAKTUS";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}