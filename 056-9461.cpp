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

ll dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    for (int i = 6; i <= N; i++)
      dp[i] = dp[i - 1] + dp[i - 5];

    cout << dp[N] << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}