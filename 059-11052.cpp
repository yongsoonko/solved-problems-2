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

int dp[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    int N;
    cin >> N;
    fill(dp, dp + 1001, 0);

    for (int i = 1; i <= N; i++) {
      int a;
      cin >> a;
      for (int j = 1; j <= N; j++)
        if (j - i >= 0)
          dp[j] = max(dp[j], dp[j - i] + a);
    }

    cout << dp[N] << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}