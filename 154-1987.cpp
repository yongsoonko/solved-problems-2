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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int R, C, ans = 1;
bool chk[26];
string map[21];

void dfs(int ci, int cj, int cnt) {
  if (cnt == 26) {
    return;
  } else {
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
        if (!chk[map[ni][nj] - 'A']) {
          ans = max(ans, cnt + 1);
          chk[map[ni][nj] - 'A'] = 1;
          dfs(ni, nj, cnt + 1);
          chk[map[ni][nj] - 'A'] = 0;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C;
  for (int i = 0; i < R; i++)
    cin >> map[i];

  chk[map[0][0] - 'A'] = 1;
  dfs(0, 0, 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}