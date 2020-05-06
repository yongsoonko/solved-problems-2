#include <algorithm>
#include <iomanip>
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
Pos air;
int R, C, T, ans;
int A[51][51], B[51][51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      cin >> A[i][j];
      if (A[i][j] == -1)
        air = {i, j};
    }

  for (int p = 0; p < T; p++) {

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        if (A[i][j] > 0) {
          int spread = 0;
          for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < R && nj >= 0 && nj < C &&
                A[ni][nj] != -1) {
              B[ni][nj] += A[i][j] / 5;
              spread += A[i][j] / 5;
            }
          }
          A[i][j] -= spread;
        }

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        A[i][j] += B[i][j];

    fill(&B[0][0], &B[R - 1][C], 0);

    for (int i = air.i - 2; i > 0; i--)
      A[i][0] = A[i - 1][0];
    for (int j = 0; j < C - 1; j++)
      A[0][j] = A[0][j + 1];
    for (int i = 0; i < air.i - 1; i++)
      A[i][C - 1] = A[i + 1][C - 1];
    for (int j = C - 1; j > 1; j--)
      A[air.i - 1][j] = A[air.i - 1][j - 1];
    A[air.i - 1][1] = 0;

    for (int i = air.i + 1; i < R - 1; i++)
      A[i][0] = A[i + 1][0];
    for (int j = 0; j < C - 1; j++)
      A[R - 1][j] = A[R - 1][j + 1];
    for (int i = R - 1; i > air.i; i--)
      A[i][C - 1] = A[i - 1][C - 1];
    for (int j = C - 1; j > 1; j--)
      A[air.i][j] = A[air.i][j - 1];
    A[air.i][1] = 0;
  }

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (A[i][j] > 0)
        ans += A[i][j];
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}