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
  string j;
};

int N;
string map[65];

Pos dfs(int ci, int cj, int sz) {
  if (sz == 1)
    return {map[ci][cj] - '0', to_string(map[ci][cj] - '0')};

  int cnt[3] = {0};
  string str;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      Pos p = dfs(ci + sz / 2 * i, cj + sz / 2 * j, sz / 2);
      cnt[p.i]++;
      str += p.j;
    }

  for (int i = 0; i <= 1; i++)
    if (cnt[i] == 4)
      return {i, to_string(i)};

  return {2, '(' + str + ')'};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> map[i];

  cout << dfs(0, 0, N).j;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}