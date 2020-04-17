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

int N;
char map[4000][8000];

void dfs(int ci, int cj, int sz) {
  if (sz == 3) {
    map[ci][cj] = map[ci + 1][cj - 1] = map[ci + 1][cj + 1] = '*';
    for (int i = -2; i <= 2; i++)
      map[ci + 2][cj + i] = '*';
  } else {
    dfs(ci, cj, sz / 2);
    dfs(ci + sz / 2, cj - sz / 2, sz / 2);
    dfs(ci + sz / 2, cj + sz / 2, sz / 2);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N * 2; j++)
      map[i][j] = ' ';

  dfs(0, N - 1, N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N * 2; j++)
      cout << map[i][j];
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}