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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int map[101][101];
bool chk[101][101];
int N, ans = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  int lo = 1000, hi = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      if (lo > map[i][j])
        lo = map[i][j];
      if (hi < map[i][j])
        hi = map[i][j];
    }

  queue<Pos> Q;
  for (int h = lo; h < hi; h++) {
    fill(&chk[0][0], &chk[N - 1][N], 0);
    int cnt = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (!chk[i][j] && map[i][j] > h) {
          cnt++;
          chk[i][j] = 1;
          Q.push({i, j});

          while (Q.size()) {
            int ci = Q.front().i, cj = Q.front().j;
            Q.pop();
            for (int k = 0; k < 4; k++) {
              int ni = ci + di[k], nj = cj + dj[k];
              if (ni >= 0 && ni < N && nj >= 0 && nj < N &&
                  !chk[ni][nj] && map[ni][nj] > h) {
                chk[ni][nj] = 1;
                Q.push({ni, nj});
              }
            }
          }
        }
    ans = max(ans, cnt);
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}