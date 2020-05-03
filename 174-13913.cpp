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

int N, K;
int dist[100001];
int from[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> K;

  fill(from, from + 100001, -1);

  dist[N] = 1;
  queue<int> Q;
  Q.push(N);

  while (Q.size()) {
    if (dist[K])
      break;
    int sz = Q.size();
    while (sz--) {
      int curr = Q.front();
      Q.pop();

      for (int next : {curr - 1, curr + 1, curr * 2})
        if (next >= 0 && next <= 100000 && !dist[next]) {
          dist[next] = dist[curr] + 1;
          from[next] = curr;
          Q.push(next);
        }
    }
  }

  cout << dist[K] - 1 << '\n';
  int p = K;
  vector<int> ans;
  ans.push_back(K);
  while (p != N) {
    ans.push_back(from[p]);
    p = from[p];
  }
  while (ans.size()) {
    cout << ans.back() << ' ';
    ans.pop_back();
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}