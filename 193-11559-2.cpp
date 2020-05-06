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
bool chk[12][6];
int cnt, ans;

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
          chk[i][j] = 1;
          queue<Pos> Q;
          Q.push({i, j});

          while (Q.size()) {
            int ci = Q.front().i, cj = Q.front().j;
            Q.pop();
            cnt++;
            for (int k = 0; k < 4; k++) {
              int ni = ci + di[k], nj = cj + dj[k];
              if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 &&
                  !chk[ni][nj] && A[ci][cj] == A[ni][nj]) {
                chk[ni][nj] = 1;
                Q.push({ni, nj});
              }
            }
          }
          if (cnt >= 4) {
            flag = 1;
            Q.push({i, j});
            char curr = A[i][j];

            while (Q.size()) {
              int ci = Q.front().i, cj = Q.front().j;
              Q.pop();
              for (int k = 0; k < 4; k++) {
                int ni = ci + di[k], nj = cj + dj[k];
                if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 &&
                    A[ni][nj] == curr) {
                  A[ni][nj] = '.';
                  Q.push({ni, nj});
                }
              }
            }
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

    if (flag)
      ans++;
    else
      break;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}