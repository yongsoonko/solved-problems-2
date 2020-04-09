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

int N;
int dp[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= N; i++)
    dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

  cout << dp[N];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}