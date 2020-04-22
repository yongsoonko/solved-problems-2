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

ll ans;
int N, M;
string map[101];

void dfs(int curr, ll mulSum, int sum, int sr, int er, int sc, int ec) {
  if (curr == 2) {
    mulSum *= sum;
    ans = max(ans, mulSum);
  } else {
    for (int i = sr + 1; i <= er; i++) {
      int s = 0;
      for (int k = sr; k < i; k++)
        for (int l = sc; l <= ec; l++)
          s += map[k][l] - '0';
      dfs(curr + 1, mulSum * (sum - s), s, sr, i - 1, sc, ec);
      dfs(curr + 1, mulSum * s, sum - s, i, er, sc, ec);
    }
    for (int j = sc + 1; j <= ec; j++) {
      int s = 0;
      for (int k = sc; k < j; k++)
        for (int l = sr; l <= er; l++)
          s += map[l][k] - '0';
      dfs(curr + 1, mulSum * (sum - s), s, sr, er, sc, j - 1);
      dfs(curr + 1, mulSum * s, sum - s, sr, er, j, ec);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = 0; j < M; j++)
      sum += map[i][j] - '0';
  }

  dfs(0, 1, sum, 0, N - 1, 0, M - 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}