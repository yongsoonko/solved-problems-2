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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int map[101][101];
Pos dist[101][101];
int N, ans = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> map[i][j];

  queue<Pos> Q;
  int cnt = 2;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == 1) {
        map[i][j] = cnt;

        queue<Pos> q;
        q.push({i, j});

        while (q.size()) {
          int ci = q.front().i, cj = q.front().j;
          q.pop();

          bool once = 1;
          for (int i = 0; i < 4; i++) {
            int ni = ci + di[i], nj = cj + dj[i];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
              if (map[ni][nj] == 1) {
                map[ni][nj] = cnt;
                q.push({ni, nj});
              }
              if (once && map[ni][nj] == 0) {
                once = 0;
                Q.push({ci, cj, cnt});
              }
            }
          }
        }
        cnt++;
      }

  while (Q.size()) {
    for (int qs = Q.size(); qs--;) {
      int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < N &&
            map[ni][nj] == 0 && dist[ni][nj].k != ck) {
          if (dist[ni][nj].k == 0) {
            dist[ni][nj] = {dist[ci][cj].i + 1, 0, ck};
            Q.push({ni, nj, ck});
          } else
            ans = min(ans, dist[ni][nj].i + dist[ci][cj].i);
        }
      }
    }
    if (ans < 1e9) {
      cout << ans;
      break;
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}