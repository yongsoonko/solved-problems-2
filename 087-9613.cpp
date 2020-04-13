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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int v[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    ll sum = 0;

    for (int i = 0; i < n; i++)
      cin >> v[i];
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        sum += gcd(v[i], v[j]);

    cout << sum << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}