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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int E, S, M;
  cin >> E >> S >> M;

  int ans = 1, e = 1, s = 1, m = 1;
  while (!(e == E && s == S && m == M)) {
    e++, s++, m++, ans++;
    if (e == 16)
      e = 1;
    if (s == 29)
      s = 1;
    if (m == 20)
      m = 1;
  }
  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}