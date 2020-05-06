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

int N, L, ans;
int A[101][101];
int chk[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> L;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  for (int i = 0; i < N; i++) {
    bool flag = 1;
    for (int j = 0; j < N - 1; j++) {
      if (A[i][j] - A[i][j + 1] == 1) {
        for (int k = 1; k <= L; k++)
          if (j + k >= N || chk[i][j + k] || A[i][j + k] != A[i][j + 1]) {
            flag = 0;
            break;
          } else
            chk[i][j + k] = 1;

      } else if (A[i][j] - A[i][j + 1] > 1)
        flag = 0;
      if (!flag)
        break;
    }
    for (int j = N - 1; j >= 1; j--) {
      if (A[i][j] - A[i][j - 1] == 1) {
        for (int k = 1; k <= L; k++)
          if (j - k < 0 || chk[i][j - k] || A[i][j - k] != A[i][j - 1]) {
            flag = 0;
            break;
          } else
            chk[i][j - k] = 1;
      } else if (A[i][j] - A[i][j - 1] > 1)
        flag = 0;
      if (!flag)
        break;
    }
    if (flag)
      ans++;
  }

  fill(&chk[0][0], &chk[N - 1][N], 0);

  for (int j = 0; j < N; j++) {
    bool flag = 1;
    for (int i = 0; i < N - 1; i++) {
      if (A[i][j] - A[i + 1][j] == 1) {
        for (int k = 1; k <= L; k++)
          if (i + k >= N || chk[i + k][j] || A[i + k][j] != A[i + 1][j]) {
            flag = 0;
            break;
          } else
            chk[i + k][j] = 1;
      } else if (A[i][j] - A[i + 1][j] > 1)
        flag = 0;
      if (!flag)
        break;
    }
    for (int i = N - 1; i >= 1; i--) {
      if (A[i][j] - A[i - 1][j] == 1) {
        for (int k = 1; k <= L; k++) {
          if (i - k < 0 || chk[i - k][j] || A[i - k][j] != A[i - 1][j]) {
            flag = 0;
            break;
          } else
            chk[i - k][j] = 1;
        }
      } else if (A[i][j] - A[i - 1][j] > 1)
        flag = 0;
      if (!flag)
        break;
    }
    if (flag)
      ans++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}