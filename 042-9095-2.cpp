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

int dp[12];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int T, N;
  cin >> T;

  dp[0] = dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= 11; i++)
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

  while (T--) {
    cin >> N;
    cout << dp[N] << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}