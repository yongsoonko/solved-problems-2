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

int N, M, V;
int chk[1001];
vector<int> E[1001];

void dfs(int curr) {
  chk[curr] = 1;
  cout << curr << ' ';

  for (int i = 0; i < E[curr].size(); i++) {
    int next = E[curr][i];
    if (!chk[next])
      dfs(next);
  }
}

void bfs(int curr) {
  chk[curr] = 1;

  queue<int> q;
  q.push(curr);

  while (q.size()) {
    curr = q.front();
    q.pop();
    cout << curr << ' ';

    for (int i = 0; i < E[curr].size(); i++) {
      int next = E[curr][i];
      if (!chk[next]) {
        chk[next] = 1;
        q.push(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  for (int i = 1; i <= N; i++)
    sort(E[i].begin(), E[i].end());

  dfs(V);
  cout << '\n';
  fill(chk, chk + 1001, 0);
  bfs(V);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}