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

int F, S, G, U, D, ans;
int dist[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> F >> S >> G >> U >> D;

  fill(dist, dist + 1000001, -1);

  dist[S] = 0;
  queue<int> Q;
  Q.push(S);

  while (Q.size()) {
    if (dist[G] >= 0) {
      cout << ans;
      return 0;
    }
    ans++;
    int sz = Q.size();
    while (sz--) {
      int curr = Q.front();
      Q.pop();

      for (int next : {curr + U, curr - D})
        if (next >= 1 && next <= F && dist[next] < 0) {
          dist[next] = dist[curr] + 1;
          Q.push(next);
        }
    }
  }
  cout << "use the stairs";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}