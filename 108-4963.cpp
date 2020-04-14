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

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int chk[51][51];
int map[51][51];
int w, h, ans;

void bfs(int ci, int cj) {
  chk[ci][cj] = 1;

  queue<Pos> q;
  q.push({ci, cj});

  while (q.size()) {
    ci = q.front().i, cj = q.front().j;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < h && nj >= 0 && nj < w &&
          !chk[ni][nj] && map[ni][nj]) {
        chk[ni][nj] = 1;
        q.push({ni, nj});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    cin >> w >> h;
    if (w == 0)
      break;

    ans = 0;
    fill(&chk[0][0], &chk[50][51], 0);

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> map[i][j];

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (!chk[i][j] && map[i][j]) {
          ans++;
          bfs(i, j);
        }

    cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}