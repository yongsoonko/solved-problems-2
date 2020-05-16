#include <algorithm>
#include <iostream>
#include <map>
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

int N, M, ans;
vector<int> E[501], E2[501];
bool chk[501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E2[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) {
    chk[i] = 1;
    queue<int> Q;
    Q.push(i);

    int gCnt = 0;
    while (Q.size()) {
      int curr = Q.front();
      Q.pop();
      for (int next : E[curr])
        if (!chk[next]) {
          chk[next] = 1;
          Q.push(next);
          gCnt++;
        }
    }
    fill(chk + 1, chk + N + 1, 0);

    chk[i] = 1;
    Q.push(i);

    int lCnt = 0;
    while (Q.size()) {
      int curr = Q.front();
      Q.pop();
      for (int next : E2[curr])
        if (!chk[next]) {
          chk[next] = 1;
          Q.push(next);
          lCnt++;
        }
    }
    fill(chk + 1, chk + N + 1, 0);

    if (lCnt + gCnt == N - 1)
      ans++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}