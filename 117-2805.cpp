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

int v[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, M, ans = 0;
  cin >> N >> M;

  int max = 0;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    if (max < v[i])
      max = v[i];
  }

  ll lt = 1, rt = max;
  while (lt <= rt) {
    ll sum = 0, mid = (lt + rt) / 2;
    for (int i = 0; i < N; i++)
      if (v[i] > mid)
        sum += v[i] - mid;
    if (sum >= M) {
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