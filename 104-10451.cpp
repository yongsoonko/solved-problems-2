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

int T, N, ans;
int chk[1001];
int E[1001];

void dfs(int curr) {
  chk[curr] = 1;

  if (!chk[E[curr]])
    dfs(E[curr]);
  else
    ans++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> T;
  while (T--) {
    cin >> N;

    ans = 0;
    fill(chk, chk + 1001, 0);
    fill(E, E + 1001, 0);

    for (int i = 1; i <= N; i++)
      cin >> E[i];

    for (int i = 1; i <= N; i++)
      if (!chk[i])
        dfs(i);

    cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}