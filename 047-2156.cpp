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

int dp[3][10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;

    if (i == 1)
      dp[1][i] = dp[0][i - 1] + a;
    else {
      dp[1][i] = dp[0][i - 1] + a;
      dp[2][i] = dp[1][i - 1] + a;
    }
    dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
  }

  cout << max(dp[0][N], max(dp[1][N], dp[2][N]));

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}