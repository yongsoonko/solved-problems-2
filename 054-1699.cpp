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

int dp[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  fill(dp, dp + 100001, 1e9);
  dp[0] = 0;

  for (int i = 1; i * i <= N; i++) {
    dp[i * i] = 1;
    for (int j = 1; j <= N; j++)
      if (j - i * i >= 0)
        dp[j] = min(dp[j], dp[j - i * i] + dp[i * i]);
  }

  cout << dp[N];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}