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

  int N, ans = -1e9;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    dp[i] = max(dp[i - 1] + a, a);
    ans = max(ans, dp[i]);
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}