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

int N, W, L, ans;
int cnt[1000], weight[1000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> W >> L;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    weight[i] = a;
  }

  int p = 0, q = 0;
  while (cnt[N - 1] <= W) {
    for (int i = p; i < q; i++)
      cnt[i]++;
    if (cnt[p] > W) {
      L += weight[p];
      p++;
    }
    if (q < N && L >= weight[q]) {
      L -= weight[q];
      cnt[q]++;
      q++;
    }
    ans++;
  }
  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}