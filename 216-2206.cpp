#include <algorithm>
#include <cassert>
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
  int k;
};

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
string A[1001];
bool chk[1001][1001][2];
int N, M, ans = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  chk[0][0][0] = 1;
  queue<Pos> Q;
  Q.push({0, 0, 0});

  while (Q.size()) {
    if (chk[N - 1][M - 1][0] || chk[N - 1][M - 1][1]) {
      cout << ans;
      return 0;
    }
    ans++;
    int sz = Q.size();
    while (sz--) {
      int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
          if (A[ni][nj] == '0' && !chk[ni][nj][ck]) {
            chk[ni][nj][ck] = 1;
            Q.push({ni, nj, ck});
          } else if (A[ni][nj] == '1' && ck == 0) {
            chk[ni][nj][1] = 1;
            Q.push({ni, nj, 1});
          }
        }
      }
    }
  }

  cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}