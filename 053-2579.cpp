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

int dp[3][301], v[301];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> v[i];

  for (int i = 1; i <= N; i++) {
    if (i == 1)
      dp[1][i] = v[1];
    else if (i == 2) {
      dp[1][i] = v[2];
      dp[2][i] = dp[1][i - 1] + v[i];
    } else {
      dp[1][i] = max(dp[1][i - 2] + v[i], dp[2][i - 2] + v[i]);
      dp[2][i] = dp[1][i - 1] + v[i];
    }
  }

  cout << max(dp[1][N], dp[2][N]);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}