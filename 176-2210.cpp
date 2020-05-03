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
int map[6][6];
int chk[1000000];
int ans;

void dfs(int add, int cnt, int ci, int cj) {
  if (cnt == 5) {
    if (chk[add] == 0) {
      chk[add] = 1;
      ans++;
    }
  } else {
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5)
        dfs(add * 10 + map[ni][nj], cnt + 1, ni, nj);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> map[i][j];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      dfs(map[i][j], 0, i, j);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}