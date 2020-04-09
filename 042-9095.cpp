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

int dp[11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int T;
  cin >> T;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 0; i < T; i++) {
    int a;
    cin >> a;

    for (int j = 4; j <= a; j++)
      dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];

    cout << dp[a] << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}