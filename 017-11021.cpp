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

  int T, idx = 1;

  cin >> T;
  while (idx <= T) {
    int a, b;
    cin >> a >> b;
    cout << "Case #" << idx << ": " << a + b << '\n';
    idx++;
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}