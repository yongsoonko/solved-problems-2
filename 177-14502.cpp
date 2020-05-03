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
int N, M, ans, zeroCnt;
int map[9][9];
int chk[9][9];
vector<Pos> virPos;

void dfs(int cnt, int ci, int cj) {
  if (cnt == 3) {
    fill(&chk[0][0], &chk[N - 1][M], 0);
    queue<Pos> Q;
    int square = 0;
    for (Pos p : virPos) {
      chk[p.i][p.j] = 1;
      Q.push(p);
    }
    while (Q.size()) {
      int sz = Q.size();
      while (sz--) {
        int ci = Q.front().i, cj = Q.front().j;
        Q.pop();
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
              !chk[ni][nj] && map[ni][nj] == 0) {
            chk[ni][nj] = 1;
            Q.push({ni, nj});
          }
        }
      }
      square += Q.size();
      if (zeroCnt - square <= ans)
        return;
    }
    ans = max(ans, zeroCnt - square);
  } else if (ci < N) {
    for (int i = ci; i < N; i++)
      for (int j = 0; j < M; j++) {
        if (i == ci && j < cj)
          continue;
        if (map[i][j] == 1 || map[i][j] == 2)
          continue;
        if (map[i][j] == 0) {
          int ni = i + (j + 1) / M,
              nj = (j + 1) % M;
          map[i][j] = 1;
          dfs(cnt + 1, ni, nj);
          map[i][j] = 0;
        }
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2)
        virPos.push_back({i, j});
      else if (map[i][j] == 0)
        zeroCnt++;
    }
  zeroCnt -= 3;

  dfs(0, 0, 0);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}