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

int v[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  ll ans = 0;
  int K, N;
  cin >> K >> N;

  int max = 0;
  for (int i = 0; i < K; i++) {
    cin >> v[i];
    if (max < v[i])
      max = v[i];
  }

  ll lt = 1, rt = max;
  while (lt <= rt) {
    ll sum = 0, mid = (lt + rt) / 2;
    for (int i = 0; i < K; i++)
      sum += v[i] / mid;
    if (sum >= N) {
      lt = mid + 1;
      if (ans < mid)
        ans = mid;
    } else
      rt = mid - 1;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}