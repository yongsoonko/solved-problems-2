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

int N;
int map[65][65];

void dfs(int ci, int cj, int sz) {
  bool flag = 1;
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      if (map[ci][cj] != map[ci + i][cj + j]) {
        flag = 0;
        goto out;
      }
out:
  if (flag) {
    cout << map[ci][cj];
    return;
  }

  cout << '(';
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      dfs(ci + sz / 2 * i, cj + sz / 2 * j, sz / 2);
  cout << ')';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < N; j++)
      map[i][j] = str[j] - '0';
  }

  dfs(0, 0, N);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}