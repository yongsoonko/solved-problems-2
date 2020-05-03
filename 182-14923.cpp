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
int N, M, Hx, Hy, Ex, Ey, ans = 1e9;
int map[1001][1001];
int dist[1001][1001][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> map[i][j];

  dist[Hx][Hy][0] = 1;

  queue<Pos> Q;
  Q.push({Hx, Hy});

  while (Q.size()) {
    int ci = Q.front().i, cj = Q.front().j;
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 1 && ni <= N && nj >= 1 && nj <= M) {
        if (map[ni][nj] == 0) {
          bool flag = 0;
          if (!dist[ni][nj][0] && dist[ci][cj][0]) {
            dist[ni][nj][0] = dist[ci][cj][0] + 1;
            flag = 1;
          }
          if (!dist[ni][nj][1] && dist[ci][cj][1]) {
            dist[ni][nj][1] = dist[ci][cj][1] + 1;
            flag = 1;
          }
          if (flag)
            Q.push({ni, nj});
        } else {
          if (!dist[ni][nj][1] && dist[ci][cj][0]) {
            dist[ni][nj][1] = dist[ci][cj][0] + 1;
            Q.push({ni, nj});
          }
        }
      }
    }
    if (dist[Ex][Ey][0] || dist[Ex][Ey][1])
      break;
  }

  if (dist[Ex][Ey][0])
    cout << dist[Ex][Ey][0] - 1;
  else if (dist[Ex][Ey][1])
    cout << dist[Ex][Ey][1] - 1;
  else
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}