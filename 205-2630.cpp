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

int N, ans[2];
bool A[130][130];

int dfs(int ci, int cj, int sz) {
  if (sz == 1)
    return A[ci][cj];
  else {
    int cnt[3]{0};
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        cnt[dfs(ci + sz / 2 * i, cj + sz / 2 * j, sz / 2)]++;

    for (int i = 0; i < 2; i++)
      if (cnt[i] == 4) {
        if (sz == N)
          ans[i]++;
        return i;
      }

    for (int i = 0; i < 2; i++)
      ans[i] += cnt[i];
    return 2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  dfs(0, 0, N);

  cout << ans[0] << '\n'
       << ans[1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}