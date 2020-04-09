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
int dp[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  dp[N] = 0;
  fill(dp, dp + N, 1e9);

  for (int i = N - 1; i >= 1; i--) {
    if (i <= N / 3)
      dp[i] = min(dp[i], dp[i * 3] + 1);
    if (i <= N / 2)
      dp[i] = min(dp[i], dp[i * 2] + 1);
    dp[i] = min(dp[i], dp[i + 1] + 1);
  }

  cout << dp[1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}