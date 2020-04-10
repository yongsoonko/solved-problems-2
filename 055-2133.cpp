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

int dp[31];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  dp[0] = 1;
  dp[2] = 3;

  if (N % 2) {
    cout << 0;
    return 0;
  } else {
    for (int i = 4; i <= N; i += 2) {
      dp[i] += dp[i - 2] * 3;
      for (int j = 4; j <= i; j += 2)
        dp[i] += dp[i - j] * 2;
    }
  }

  cout << dp[N];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}