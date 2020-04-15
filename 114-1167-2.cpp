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

vector<Pos> E[100001];
int dist[100001];
int chk[100001];
int V, ans, pos;

void bfs(int curr) {
  chk[curr] = 1;

  queue<int> q;
  q.push(curr);

  while (q.size()) {
    for (int qs = q.size(); qs--;) {
      curr = q.front();
      q.pop();

      for (Pos next : E[curr]) {
        if (!chk[next.i]) {
          chk[next.i] = 1;
          dist[next.i] = dist[curr] + next.j;
          q.push(next.i);
        }
      }
    }
  }
  ans = 0;
  for (int i = 1; i <= V; i++)
    if (ans < dist[i]) {
      ans = dist[i];
      pos = i;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> V;

  for (int i = 1; i <= V; i++) {
    int a, b, c;
    cin >> a;
    while (1) {
      cin >> b;
      if (b == -1)
        break;
      cin >> c;
      E[a].push_back({b, c});
    }
  }

  bfs(1);

  fill(chk, chk + V + 1, 0);
  fill(dist, dist + V + 1, 0);

  bfs(pos);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}