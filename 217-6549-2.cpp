#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int N;
int H[100002];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    cin >> N;
    if (N == 0)
      break;

    stack<int> S;
    ll ans = 0;

    for (int i = 1; i <= N; i++)
      cin >> H[i];
    H[N + 1] = 0;

    S.push(0);
    for (int i = 1; i <= N + 1; i++) {
      while (S.size() && H[S.top()] > H[i]) {
        int h = H[S.top()];
        S.pop();
        int w = i - (S.top() + 1);
        ans = max(ans, (ll)w * h);
      }
      S.push(i);
    }

    cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}