#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
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
  return b == 0 ? a : gcd(b, a % b);
}

long long solution(int w, int h) {
  long long ans = (ll)w * h;
  double slope = (double)h / w;
  int g = gcd(w, h), cnt = 0, prev = 0, curr, W = w / g;
  for (int i = 1; i < W; i++) {
    curr = floor(slope * i);
    cnt += curr - prev + 1;
    prev = curr;
  }
  // (double)100000000/99999999 * 99999999 = 99999999
  cnt += (h / g) - prev;
  ans -= cnt * g;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cout << setprecision(10) << ((double)100000000 / 99999999) * 99999998 << '\n';
  // cout << solution(100000000, 99999999);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}