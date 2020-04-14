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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int chk[26][26];
string map[26];
int N, cnt;
vector<int> v;

void dfs(int ci, int cj) {
  chk[ci][cj] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < N &&
        !chk[ni][nj] && (map[ni][nj] == map[ci][cj]))
      dfs(ni, nj);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> map[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (!chk[i][j] && map[i][j] > '0') {
        cnt = 0;
        dfs(i, j);
        v.push_back(cnt);
      }

  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for (int i : v)
    cout << i << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}