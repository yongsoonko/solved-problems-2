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

int v[200001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  ll ans = 1;
  int N, C;
  cin >> N >> C;

  for (int i = 0; i < N; i++)
    cin >> v[i];

  sort(v, v + N);

  ll lt = 1, rt = v[N - 1] - v[0];
  while (lt <= rt) {
    ll cnt = 1, prev = v[0], mid = (lt + rt) / 2;
    for (int i = 1; i < N; i++)
      if (v[i] - prev >= mid) {
        prev = v[i];
        cnt++;
      }
    if (cnt >= C) {
      lt = mid + 1;
      ans = max(ans, mid);
    } else
      rt = mid - 1;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}