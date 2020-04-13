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

  int N, M;
  cin >> N >> M;

  Pos a, b, c;
  a = b = c = {0, 0};
  for (ll i = 2; i <= N; i *= 2) {
    a.i += N / i;
    b.i += M / i;
    c.i += (N - M) / i;
  }

  for (ll i = 5; i <= N; i *= 5) {
    a.j += N / i;
    b.j += M / i;
    c.j += (N - M) / i;
  }

  cout << min(a.i - b.i - c.i, a.j - b.j - c.j);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}