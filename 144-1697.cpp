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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> K;

  dist[N] = 1;
  queue<int> Q;
  Q.push(N);

  while (Q.size()) {
    for (int sz = Q.size(); sz--;) {
      int curr = Q.front();
      Q.pop();

      for (int next : {curr - 1, curr + 1, curr * 2})
        if (next >= 0 && next <= 100000 && !dist[next]) {
          dist[next] = dist[curr] + 1;
          Q.push(next);
        }
    }
    if (dist[K])
      break;
  }

  cout << dist[K] - 1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}