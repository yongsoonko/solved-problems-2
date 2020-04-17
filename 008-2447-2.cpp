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
char map[3000][3000];

void dfs(int ci, int cj, int sz) {
  if (sz == 1) {
    map[ci][cj] = '*';
    return;
  }

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1)
        continue;
      dfs(ci + sz / 3 * i, cj + sz / 3 * j, sz / 3);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      map[i][j] = ' ';

  dfs(0, 0, N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << map[i][j];
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}