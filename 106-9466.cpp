#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;  // 연결그래프(팀)의 번호
  int j;  // 연결그래프(팀)의 순회 횟수 
};
// ans는 팀원수 카운트, cnt는 팀번호 카운트
int T, N, ans, cnt;
Pos chk[100001];
int E[100001];

void dfs(int curr) {
  int next = E[curr];
  if (chk[next].i == 0) {
    chk[next] = {cnt, chk[curr].j + 1};
    dfs(next);
  } else if (chk[next].i == cnt)
    ans += chk[curr].j - chk[next].j + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> T;

  while (T--) {
    cin >> N;
    ans = cnt = 0;
    for (int i = 1; i <= N; i++)
      chk[i] = {0, 0};
    fill(E + 1, E + N + 1, 0);

    for (int i = 1; i <= N; i++)
      cin >> E[i];

    for (int i = 1; i <= N; i++)
      if (!chk[i].i) {
        cnt++;
        chk[i] = {cnt, 1};
        dfs(i);
      }

    cout << N - ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}