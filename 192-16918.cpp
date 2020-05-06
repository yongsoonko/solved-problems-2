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
int R, C, N;
char A[201][201], B[201][201];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C >> N;

  for (int i = 0; i < R; i++)
    cin >> A[i];

  if (N == 1)
    for (int i = 0; i < R; i++)
      cout << A[i] << '\n';
  else {
    for (int p = 2; p <= N; p++) {
      if (p % 2 == 0)
        fill(&B[0][0], &B[R - 1][C], 'O');
      else {
        for (int i = 0; i < R; i++)
          for (int j = 0; j < C; j++)
            if (A[i][j] == 'O') {
              B[i][j] = '.';
              for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < R && nj >= 0 && nj < C)
                  B[ni][nj] = '.';
              }
            }
        copy(&B[0][0], &B[R - 1][C], &A[0][0]);
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++)
        cout << B[i][j];
      cout << '\n';
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}