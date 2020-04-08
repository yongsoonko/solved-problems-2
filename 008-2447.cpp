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
char ans[3000][3000];

void dfs(int width, int si, int sj) {
  if (width == 1)
    ans[si][sj] = '*';
  else {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i == 1 && j == 1) {
          int ni = si + i * width / 3, nj = sj + j * width / 3;
          for (int k = 0; k < width / 3; k++)
            for (int l = 0; l < width / 3; l++)
              ans[ni + k][nj + l] = ' ';
        } else
          dfs(width / 3, si + i * width / 3, sj + j * width / 3);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  dfs(N, 0, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << ans[i][j];
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}