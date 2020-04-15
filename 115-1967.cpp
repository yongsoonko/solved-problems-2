#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;      // 부모노드 번호
  unsigned j; // 부모노드 기준으로 자식노드 번호
};

int N, ans;
Pos P[10001]; // 자식노드가 부모노드의 몇 번째 자식인지 구분
vector<int> E[10001];
vector<int> lv[10001]; // 트리의 레벨 단위 노드집합
vector<int> dp[10001]; // 각 노드의 서브트리 지름(전체트리 지름X)

bool comp(int a, int b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    E[a].push_back(b);
    P[b] = {a, dp[a].size()};
    dp[a].push_back(c);
  }

  queue<int> q;
  q.push(1);

  int cnt = 0;
  while (q.size()) {
    cnt++;
    for (int qs = q.size(); qs--;) {
      int curr = q.front();
      q.pop();

      lv[cnt].push_back(curr);
      for (int next : E[curr])
        q.push(next);
    }
  }

  // 트리 DP방식으로 리프노드에서 루트노드까지 진행하면서
  // 최대 가중치값을 갱신
  for (int i = cnt - 1; i >= 1; i--)
    for (int curr : lv[i]) {
      int max = 0;
      for (int j : dp[curr])
        if (max < j)
          max = j;
      if (P[curr].i)
        dp[P[curr].i][P[curr].j] += max;
    }

  for (int i = 1; i <= N; i++) {
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