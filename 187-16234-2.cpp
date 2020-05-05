#include <algorithm>
#include <iostream>
#include <map>
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
int N, L, R, sum, cnt, flag;
int A[51][51];
bool chk[51][51], chk2[51][51];

void dfs(int ci, int cj) {
  chk[ci][cj] = 1;
  sum += A[ci][cj];
  cnt++;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
      int diff = abs(A[ci][cj] - A[ni][nj]);
      if (!chk[ni][nj] && L <= diff && diff <= R) {
        flag = 0;
        dfs(ni, nj);
      }
    }
  }
}

void dfs2(int ci, int cj, int avg) {
  chk2[ci][cj] = 1;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
      int diff = abs(A[ci][cj] - A[ni][nj]);
      if (chk[ni][nj] && !chk2[ni][nj] && L <= diff && diff <= R)
        dfs2(ni, nj, avg);
    }
  }
  A[ci][cj] = avg;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  for (int ans = 0; ans <= 2000; ans++) {
    flag = 1;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (!chk[i][j]) {
          sum = 0, cnt = 0;
          dfs(i, j);
          dfs2(i, j, sum / cnt);
        }
    if (flag) {
      cout << ans;
      return 0;
    }
    fill(&chk[0][0], &chk[N - 1][N], 0);
    fill(&chk2[0][0], &chk2[N - 1][N], 0);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}