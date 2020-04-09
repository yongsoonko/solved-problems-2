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

int dp[1001][10] = {
    {0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, sum = 0;
  cin >> N;

  for (int i = 2; i <= N; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = j; k <= 9; k++)
        dp[i][k] = (dp[i][k] + dp[i - 1][j]) % 10007;

  for (int i = 0; i <= 9; i++)
    sum = (sum + dp[N][i]) % 10007;

  cout << sum;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}