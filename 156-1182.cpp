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

int N, S, ans;
int A[21];

void dfs(int curr, int add) {
  if (curr == N) {
    if (add == S)
      ans++;
  } else {
    dfs(curr + 1, add + A[curr]);
    dfs(curr + 1, add);
  }
}

void dfs(int curr, int add, int dummy) {
  if (add == S)
    ans++;
  for (int i = curr; i < N; i++)
    dfs(i + 1, add + A[i], 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  // dfs(0, 0);
  dfs(0, 0, 0);
  cout << (S == 0 ? ans - 1 : ans);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}