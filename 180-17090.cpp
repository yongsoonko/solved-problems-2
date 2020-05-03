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
int root[501][501];
bool outChk[501][501];

int find(int x) {
  int i = x / 501, j = x % 501;
  if (root[i][j] == -1)
    return root[i][j] = x;
  if (root[i][j] == x)
    return x;
  return root[i][j] = find(root[i][j]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);

  if (x != y)
    root[x / 501][x % 501] = y;
}

int dfs(int ci, int cj) {
  int ni, nj;
  if (map[ci][cj] == 'U')
    ni = ci - 1, nj = cj;
  else if (map[ci][cj] == 'R')
    ni = ci, nj = cj + 1;
  else if (map[ci][cj] == 'D')
    ni = ci + 1, nj = cj;
  else
    ni = ci, nj = cj - 1;
  if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
    if (find(ci * 501 + cj) != find(ni * 501 + nj)) {
      merge(ci * 501 + cj, ni * 501 + nj);
      return outChk[ci][cj] = dfs(ni, nj);
    } else
      return outChk[ci][cj] = outChk[ni][nj];
  } else
    return outChk[ci][cj] = 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> map[i];

  fill(&root[0][0], &root[N - 1][M], -1);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (root[i][j] == -1)
        outChk[i][j] = dfs(i, j);
      ans += outChk[i][j];
    }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}