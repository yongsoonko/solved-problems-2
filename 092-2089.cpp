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

  string ans;
  int N;
  cin >> N;

  // N이 0일 때도 수행하게끔
  do {
    if (N % (-2) && N < 0) {
      ans.push_back('1');
      N = N / (-2) + 1;
    } else {
      ans.push_back('0' + N % (-2));
      N = N / (-2);
    }
  } while (N);

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}