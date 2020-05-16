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

int N, ans;
int H[100002];
stack<int> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> H[i];

  S.push(0);
  for (int i = 1; i <= N + 1; i++) {
    while (S.size() && H[S.top()] > H[i]) {
      int h = H[S.top()];
      S.pop();
      int w = i - (S.top() + 1);
      ans = max(ans, w * h);
    }
    S.push(i);
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}