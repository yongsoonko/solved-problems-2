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
  int k;
};

int di[6] = {-1, 0, 1, 0, 0, 0},
    dj[6] = {0, 1, 0, -1, 0, 0},
    dk[6] = {0, 0, 0, 0, 1, -1};
int M, N, H, ans;
int A[101][101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  queue<Pos> Q;

  cin >> M >> N >> H;
  for (int k = 0; k < H; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        cin >> A[i][j][k];
        if (A[i][j][k] == 1) {
          Q.push({i, j, k});
        }
      }

  while (Q.size()) {
    int sz = Q.size();
    while (sz--) {
      int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
      Q.pop();
      for (int i = 0; i < 6; i++) {
        int ni = ci + di[i], nj = cj + dj[i], nk = ck + dk[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M && nk >= 0 && nk < H &&
            A[ni][nj][nk] == 0) {
          A[ni][nj][nk] = 1;
          Q.push({ni, nj, nk});
        }
      }
    }
    if (Q.size() == 0)
      break;
    ans++;
  }

  for (int k = 0; k < H; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (A[i][j][k] == 0) {
          cout << -1;
          return 0;
        }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}