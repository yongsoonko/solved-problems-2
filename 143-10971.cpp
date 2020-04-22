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

int N, ans = 1e9;
int W[11][11], chk[11];

void dfs(int curr, int cnt, int add) {
  if (cnt == N) {
    if (W[curr][1])
      ans = min(ans, add + W[curr][1]);
  } else {
    for (int i = 1; i <= N; i++)
      if (!chk[i] && W[curr][i]) {
        chk[i] = 1;
        dfs(i, cnt + 1, add + W[curr][i]);
        chk[i] = 0;
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> W[i][j];

  chk[1] = 1;
  dfs(1, 1, 0);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}