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

int N, ans;
int A[8], B[8], chk[8];

void dfs(int curr) {
  if (curr == N) {
    int sum = 0;
    for (int i = 1; i < N; i++)
      sum += abs(B[i - 1] - B[i]);
    ans = max(ans, sum);
  } else {
    for (int i = 0; i < N; i++)
      if (!chk[i]) {
        chk[i] = 1;
        B[curr] = A[i];
        dfs(curr + 1);
        chk[i] = 0;
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  dfs(0);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}