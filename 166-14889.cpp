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

int N, ans = 2e9;
int chk[21], A[11], B[11];
int S[21][21];

void dfs(int cnt, int curr) {
  if (cnt == N / 2) {
    int p = 0, q = 0;
    for (int i = 1; i <= N; i++) {
      if (chk[i])
        A[p++] = i;
      else
        B[q++] = i;
    }
    int sumA = 0;
    for (int i = 0; i < cnt; i++)
      for (int j = 0; j < cnt; j++)
        sumA += S[A[i]][A[j]];
    int sumB = 0;
    for (int i = 0; i < cnt; i++)
      for (int j = 0; j < cnt; j++)
        sumB += S[B[i]][B[j]];
    ans = min(ans, abs(sumA - sumB));
  } else if (curr <= N) {
    chk[curr] = 1;
    dfs(cnt + 1, curr + 1);
    chk[curr] = 0;
    dfs(cnt, curr + 1);
  }
  // curr == N + 1일 때 알아서 종료
}

void dfs2(int cnt, int curr) {
  if (cnt == N / 2) {
    int p = 0, q = 0;
    for (int i = 1; i <= N; i++) {
      if (chk[i])
        A[p++] = i;
      else
        B[q++] = i;
    }
    int sumA = 0;
    for (int i = 0; i < cnt; i++)
      for (int j = 0; j < cnt; j++)
        sumA += S[A[i]][A[j]];
    int sumB = 0;
    for (int i = 0; i < cnt; i++)
      for (int j = 0; j < cnt; j++)
        sumB += S[B[i]][B[j]];
    ans = min(ans, abs(sumA - sumB));
  } else {
    for (int i = curr; i <= N; i++) {
      chk[i] = 1;
      dfs(cnt + 1, i + 1);
      chk[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> S[i][j];

  // dfs(0, 1);
  dfs2(0, 1);
  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}