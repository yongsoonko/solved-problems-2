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

  int N, min = 1e9, max = -1e9;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a < min)
      min = a;
    if (a > max)
      max = a;
  }

  cout << min << ' ' << max;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}