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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int w, h, ans;
string map[21];
int chk[21][21][1025];
vector<Pos> dirty;

// *.o.*..........
// .........**....
// .*.............
// ...............
// ...............
// ...............
// x.......*....*.

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    cin >> w >> h;
    if (w == 0)
      break;

    ans = 0;
    fill(&chk[0][0][0], &chk[h - 1][w - 1][1025], 0);
    vector<Pos>().swap(dirty);

    queue<Pos> Q;

    for (int i = 0; i < h; i++) {
      cin >> map[i];
      for (int j = 0; j < w; j++)
        if (map[i][j] == 'o') {
          chk[i][j][0] = 1;
          Q.push({i, j, 0});
          map[i][j] = '.';
        } else if (map[i][j] == '*')
          dirty.push_back({i, j});
    }

    int flag = 0;
    while (Q.size()) {
      if (dirty.size() == 0) {
        flag = 1;
        break;
      }
      ans++;
      int sz = Q.size();
      while (sz--) {
        int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
        Q.pop();
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
            if (map[ni][nj] == '.' && !chk[ni][nj][ck]) {
              chk[ni][nj][ck] = 1;
              Q.push({ni, nj, ck});
            } else if (map[ni][nj] == '*') {
              int d = 1;
              for (int j = 0; j < dirty.size(); j++) {
                d <<= 1;
                if (dirty[j].i == ni && dirty[j].j == nj)
                  break;
              }
              d >>= 1;
              if (!(d & ck)) {
                int nk = d + ck;
                chk[ni][nj][nk] = 1;
                Q.push({ni, nj, nk});
                if (nk == ((1 << dirty.size()) - 1)) {
                  flag = 1;
                  goto out;
                }
                // 이미 청소한 지점이면 nk가 아닌 ck로 검사해야 함.
              } else if (!chk[ni][nj][ck]) {
                chk[ni][nj][ck] = 1;
                Q.push({ni, nj, ck});
              }
            }
          }
        }
      }
    }
  out:
    if (flag)
      cout << ans;
    else
      cout << -1;
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}