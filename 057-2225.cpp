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

int dp[201][201];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, K;
  cin >> N >> K;

  for (int i = 0; i <= N; i++)
    dp[1][i] = 1;

  for (int i = 2; i <= K; i++)
    for (int j = 0; j <= N; j++) {
      if (j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
    }

  cout << dp[K][N];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}