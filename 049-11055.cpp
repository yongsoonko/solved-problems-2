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

int dp[1001], v[1001];

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
      if (v[i] > v[j] && max < dp[j])
        max = dp[j];
    dp[i] = max + v[i];
    if (ans < dp[i])
      ans = dp[i];
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}