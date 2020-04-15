#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  unsigned i;
  unsigned j;
};

Pos P[100001];         // Pos.i : 부모노드 번호, Pos.j : 부모노드 dp인덱스
vector<Pos> E[100001]; // Pos.i : 인접노드 번호, Pos.j : 가중치
vector<int> lv[100001];
vector<int> dp[100001];
int chk[100001];
int V, ans;

bool comp(int a, int b){
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> V;

  for (int i = 1; i <= V; i++) {
    unsigned a, b, c;
    cin >> a;
    while (1) {
      cin >> b;
      if (b == -1)
        break;
      cin >> c;
      E[a].push_back({b, c});
    }
  }

  queue<int> q;
  chk[1] = 1;
  q.push(1);

  int cnt = 0;
  while (q.size()) {
    cnt++;
    for (int qs = q.size(); qs--;) {
      unsigned curr = q.front();
      q.pop();

      lv[cnt].push_back(curr);
      for (Pos next : E[curr]) {
        if (!chk[next.i]) {
          chk[next.i] = 1;
          q.push(next.i);
          P[next.i] = {curr, dp[curr].size()};
          dp[curr].push_back(next.j);
        }
      }
    }
  }

  for (int i = cnt - 1; i >= 1; i--)
    for (int curr : lv[i]) {
      int max = 0;
      for (int j : dp[curr])
        if (max < j)
          max = j;
      if (P[curr].i)
        dp[P[curr].i][P[curr].j] += max;
    }

  for (int i = 1; i <= V; i++) {
    if (dp[i].size() == 1)
      ans = max(ans, dp[i].back());
    else if (dp[i].size() >= 2) {
      sort(dp[i].begin(), dp[i].end(), comp);
      ans = max(ans, dp[i][0] + dp[i][1]);
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}