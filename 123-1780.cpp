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
int ans[3];
int map[3000][3000];

int dfs(int ci, int cj, int sz) {
  if (sz == 1) {
    if (map[ci][cj] == -1)
      return 2;
    else
      return map[ci][cj];
  }

  // 0: 0의개수, 1: 1의개수, 2: -1의개수, 3:제외
  int chk[4] = {0};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      chk[dfs(ci + sz / 3 * i, cj + sz / 3 * j, sz / 3)]++;

  for (int i = 0; i <= 2; i++)
    if (chk[i] == 9) {
      if (sz == N)
        ans[i]++;
      return i;
    }

  for (int i = 0; i <= 2; i++)
    ans[i] += chk[i];
  return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> map[i][j];

  dfs(0, 0, N);

  cout << ans[2] << '\n'
       << ans[0] << '\n'
       << ans[1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}