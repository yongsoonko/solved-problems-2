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

int dp[3][100001], v[2][100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    fill(&dp[0][0], &dp[2][N], 0);
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= N; j++)
        cin >> v[i][j];

    for (int i = 1; i <= N; i++) {
      dp[0][i] = max(dp[0][i], dp[1][i - 1] + v[0][i]);
      dp[0][i] = max(dp[0][i], dp[2][i - 1] + v[0][i]);
      dp[1][i] = max(dp[1][i], dp[0][i - 1] + v[1][i]);
      dp[1][i] = max(dp[1][i], dp[2][i - 1] + v[1][i]);
      dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }

    cout << max(dp[0][N], max(dp[1][N], dp[2][N])) << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}