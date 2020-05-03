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
int N, M, zeroCnt, ans = 1e9;
int map[51][51];
int chk[51][51];
int virChk[11];
vector<Pos> vir;

void dfs(int cnt, int curr) {
  if (cnt == M) {
    int square = 0, round = 0;
    queue<Pos> Q;
    fill(&chk[0][0], &chk[N - 1][N], 0);
    for (int i = 0; i < vir.size(); i++)
      if (virChk[i]) {
        Pos p = vir[i];
        chk[p.i][p.j] = 1;
        Q.push({p.i, p.j});
      }
    while (Q.size()) {
      if (square == zeroCnt)
        break;
      round++;
      int sz = Q.size();
      while (sz--) {
        int ci = Q.front().i, cj = Q.front().j;
        Q.pop();
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < N &&
              !chk[ni][nj] && map[ni][nj] != 1) {
            if (map[ni][nj] == 0)
              square++;
            chk[ni][nj] = 1;
            Q.push({ni, nj});
          }
        }
      }
    }
    if (square == zeroCnt)
      ans = min(ans, round);
  } else if (curr < vir.size()) {
    virChk[curr] = 1;
    dfs(cnt + 1, curr + 1);
    virChk[curr] = 0;
    dfs(cnt, curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2)
        vir.push_back({i, j});
      else if (map[i][j] == 0)
        zeroCnt++;
    }

  dfs(0, 0);

  cout << (ans < 1e9 ? ans : -1);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}