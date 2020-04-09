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

int dp[2][1002], v[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, ans = 0;
  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> v[i];

  for (int i = 1; i <= N; i++) {
    int max = 0;
    for (int j = 0; j < i; j++)
      if (v[i] > v[j] && max < dp[0][j])
        max = dp[0][j];
    dp[0][i] = max + 1;
  }

  for (int i = N; i >= 1; i--) {
    int max = 0;
    for (int j = N; j > i; j--)
      if (v[i] > v[j] && max < dp[1][j])
        max = dp[1][j];
    dp[1][i] = max + 1;
  }

  for (int i = 1; i <= N; i++)
    ans = max(ans, dp[0][i] + dp[1][i]);

  cout << ans - 1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}