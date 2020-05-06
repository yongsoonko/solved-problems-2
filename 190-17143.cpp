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
  int s;
  int d;
  int z;
};

int di[4] = {-1, 1, 0, 0},
    dj[4] = {0, 0, 1, -1};
int R, C, M, ans;
Pos A[101][101], B[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C >> M;
  for (int i = 0; i < M; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    r--, c--, d--;
    A[r][c] = {s, d, z};
  }

  for (int p = 0; p < C; p++) {
    for (int i = 0; i < R; i++)
      if (A[i][p].z) {
        ans += A[i][p].z;
        A[i][p].z = 0;
        break;
      }

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        if (A[i][j].z) {
          int ni = i, nj = j, diff;
          if (A[i][j].d <= 1) {
            diff = A[i][j].s % (R * 2 - 2);
            for (int k = 0; k < diff; k++) {
              if (ni + di[A[i][j].d] < 0 || ni + di[A[i][j].d] >= R)
                A[i][j].d = !A[i][j].d;
              ni += di[A[i][j].d];
            }
          } else {
            diff = A[i][j].s % (C * 2 - 2);
            for (int k = 0; k < diff; k++) {
              if (nj + dj[A[i][j].d] < 0 || nj + dj[A[i][j].d] >= C)
                A[i][j].d = !(A[i][j].d - 2) + 2;
              nj += dj[A[i][j].d];
            }
          }
          if (B[ni][nj].z && B[ni][nj].z < A[i][j].z)
            B[ni][nj] = A[i][j];
          else if (B[ni][nj].z == 0)
            B[ni][nj] = A[i][j];
        }

    copy(&B[0][0], &B[R - 1][C], &A[0][0]);
    fill(&B[0][0], &B[R - 1][C], Pos({0, 0, 0}));
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}