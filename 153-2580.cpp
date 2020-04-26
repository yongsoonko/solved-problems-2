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
int O[100];
int map[10][10];
int chk[10][10][10];

bool dfs(int cnt) {
  if (cnt == N) {
    return 1;
  } else {
    int curr = O[cnt];
    int ci = curr / 10, cj = curr % 10;
    // 행 검사(ci 상수)
    for (int i = 1; i <= 9; i++)
      if (i != cj)
        chk[ci][cj][map[ci][i]] = 1;

    // 열 검사(cj 상수)
    for (int i = 1; i <= 9; i++)
      if (i != ci)
        chk[ci][cj][map[i][cj]] = 1;

    // 박스 검사
    int bi = (ci - 1) / 3, bj = (cj - 1) / 3;
    bi = bi * 3 + 1, bj = bj * 3 + 1;
    for (int i = bi + 2; i >= bi; i--)
      for (int j = bj + 2; j >= bj; j--)
        if (!(i == ci && j == cj))
          chk[ci][cj][map[i][j]] = 1;

    for (int i = 1; i <= 9; i++)
      if (chk[ci][cj][i] == 0) {
        map[ci][cj] = i;
        if (dfs(cnt + 1))
          return 1;
      }

    fill(chk[ci][cj] + 1, chk[ci][cj] + 10, 0);
    map[ci][cj] = 0;
    return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++) {
      cin >> map[i][j];
      if (map[i][j] == 0)
        O[N++] = i * 10 + j;
    }

  dfs(0);

  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++)
      cout << map[i][j] << ' ';
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}