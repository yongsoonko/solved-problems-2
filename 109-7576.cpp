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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int map[1001][1001];
int M, N, ans = -1;

void bfs() {
  queue<Pos> q;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 1) 
        q.push({i, j});

  while (q.size()) {
    ans++;
    for (int qs = q.size(); qs--;) {
      int ci = q.front().i, cj = q.front().j;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
            map[ni][nj] == 0) {
          map[ni][nj] = 1;
          q.push({ni, nj});
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  ans = -1;
  fill(&map[0][0], &map[N - 1][M], 0);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  bfs();

  int flag = 1;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 0) {
        cout << -1 << '\n';
        flag = 0;
        goto out;
      }
out:
  if (flag) {
    if (ans == -1)
      cout << 0 << '\n';
    else
      cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}