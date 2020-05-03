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

int N, M, ans;
string map[501];
int chk[501][501];
int cycleOrOut[501][501];

int dfs(int ci, int cj) {
  if (ci < 0 || ci >= N || cj < 0 || cj >= M)
    return 1;
  else if (chk[ci][cj])
    return 2;
  else if (cycleOrOut[ci][cj] == 1 || cycleOrOut[ci][cj] == 2)
    return cycleOrOut[ci][cj];
  else {
    int ni, nj;
    if (map[ci][cj] == 'U')
      ni = ci - 1, nj = cj;
    else if (map[ci][cj] == 'R')
      ni = ci, nj = cj + 1;
    else if (map[ci][cj] == 'D')
      ni = ci + 1, nj = cj;
    else
      ni = ci, nj = cj - 1;
    chk[ci][cj] = 1;
    cycleOrOut[ci][cj] = dfs(ni, nj);
    chk[ci][cj] = 0;
    return cycleOrOut[ci][cj];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> map[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (dfs(i, j) == 1)
        ans++;

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}