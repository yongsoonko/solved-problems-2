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

  if (N == 1) {
    cout << 1;
  } else if (N == 2)
    cout << min((M + 1) / 2, 4);
  else if (N > 2) {
    if (M <= 6)
      cout << min(M, 4);
    else
      cout << 4 + M - 6;
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}