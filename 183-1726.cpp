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

int di[4] = {0, 0, 1, -1},
    dj[4] = {1, -1, 0, 0};
int map[101][101];
int chk[101][101][4];
int M, N, Sx, Sy, Sd, Ex, Ey, Ed, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++)
      cin >> map[i][j];

  cin >> Sx >> Sy >> Sd >> Ex >> Ey >> Ed;
  Sd--, Ed--;

  chk[Sx][Sy][Sd] = 1;
  queue<Pos> Q;
  Q.push({Sx, Sy, Sd});

  while (Q.size()) {
    if (chk[Ex][Ey][Ed])
      break;
    ans++;
    int sz = Q.size();
    while (sz--) {
      int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
      Q.pop();

      for (int i = 1; i <= 3; i++) {
        int ni = ci + di[ck] * i, nj = cj + dj[ck] * i;
        if (ni >= 1 && ni <= M && nj >= 1 && nj <= N &&
            !chk[ni][nj][ck]) {
          // 도중에 1이 있으면 중단함.
          if (map[ni][nj])
            break;
          chk[ni][nj][ck] = 1;
          Q.push({ni, nj, ck});
        }
      }
      // 0 or 1(동 or 서) -> 2 or 3
      if (ck == 0 || ck == 1) {
        for (int nk = 2; nk <= 3; nk++)
          if (!chk[ci][cj][nk]) {
            chk[ci][cj][nk] = 1;
            Q.push({ci, cj, nk});
          }
      } else {
        for (int nk = 0; nk <= 1; nk++)
          if (!chk[ci][cj][nk]) {
            chk[ci][cj][nk] = 1;
            Q.push({ci, cj, nk});
          }
      }
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}