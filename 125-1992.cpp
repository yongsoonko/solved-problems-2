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

  Pos tmp[4];
  int cnt[3] = {0};

  int k = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      tmp[k] = dfs(ci + sz / 2 * i, cj + sz / 2 * j, sz / 2);
      cnt[tmp[k++].i]++;
    }

  int idx;
  if (cnt[idx = 0] == 4 || cnt[idx = 1] == 4) {
    if (sz == N)
      return {0, to_string(idx)};
    return {idx, ""};
  } else {
    string str = "(";
    for (int i = 0; i < 4; i++)
      if (tmp[i].i == 2)
        str += tmp[i].j;
      else
        str += to_string(tmp[i].i);
    str += ")";
    return {2, str};
  }
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