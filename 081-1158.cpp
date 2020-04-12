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

vector<int> ans;
int v[5001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++)
    v[i] = i;

  int pos = 1, cnt = 0;
  while (ans.size() < N) {
    if (pos == N + 1)
      pos = 1;
    if (v[pos])
      cnt++;
    if (cnt == K) {
      ans.push_back(v[pos]);
      v[pos] = 0;
      cnt = 0;
    }
    pos++;
  }

  cout << '<';
  for (int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] << ", ";
  cout << ans.back() << '>';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}