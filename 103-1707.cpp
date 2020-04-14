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

int K, V, E;
int chk[20001];
vector<int> D[20001];

void bfs(int curr) {
  int color = 1;
  chk[curr] = color;

  queue<int> q;
  q.push(curr);

  while (q.size()) {
    color = color == 1 ? 2 : 1;
    for (int qs = q.size(); qs--;) {
      curr = q.front();
      q.pop();

      for (int next : D[curr])
        if (!chk[next]) {
          chk[next] = color;
          q.push(next);
        }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> K;
  while (K--) {
    cin >> V >> E;

    fill(chk, chk + 20001, 0);
    for (int i = 1; i <= V; i++)
      vector<int>().swap(D[i]);

    for (int i = 0; i < E; i++) {
      int a, b;
      cin >> a >> b;
      D[a].push_back(b);
      D[b].push_back(a);
    }

    for (int i = 1; i <= V; i++)
      if (chk[i] == 0)
        bfs(i);

    int flag = 1;
    for (int i = 1; i <= V; i++) {
      for (int next : D[i]) {
        if (chk[next] == chk[i]) {
          flag = 0;
          cout << "NO\n";
          goto out;
        }
      }
    }
  out:
    if (flag)
      cout << "YES\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}