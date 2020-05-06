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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
string A[12];
bool chk[12][6], chk2[12][6];
int cnt, ans;

void dfs(int ci, int cj) {
  cnt++;
  chk[ci][cj] = 1;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 &&
        !chk[ni][nj] && A[ni][nj] == A[ci][cj]) {
      chk[ni][nj] = 1;
      dfs(ni, nj);
    }
  }
}

void dfs2(int ci, int cj) {
  chk2[ci][cj] = 1;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 &&
        !chk2[ni][nj] && A[ni][nj] == A[ci][cj]) {
      chk2[ni][nj] = 1;
      dfs2(ni, nj);
    }
  }
  A[ci][cj] = '.';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 0; i < 12; i++)
    cin >> A[i];

  while (1) {
    int flag = 0;
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 6; j++)
        if (A[i][j] != '.' && !chk[i][j]) {
          cnt = 0;
          dfs(i, j);
          if (cnt >= 4) {
            dfs2(i, j);
            flag = 1;
          }
        }
    for (int j = 0; j < 6; j++) {
      string str;
      for (int i = 0; i < 12; i++)
        if (A[i][j] != '.')
          str.push_back(A[i][j]);
      int p = 11;
      for (int i = 11; i >= 0; i--)
        if (str.size()) {
          A[i][j] = str.back();
          str.pop_back();
        } else
          A[i][j] = '.';
    }
    fill(&chk[0][0], &chk[11][6], 0);
    fill(&chk2[0][0], &chk2[11][6], 0);

    if (flag)
      ans++;
    else
      break;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}