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

  int N, B;
  cin >> N >> B;

  string ans;
  while (N) {
    int d = N % B;
    if (d >= 10)
      ans.push_back('A' + d - 10);
    else
      ans.push_back('0' + d);
    N /= B;
  }

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}