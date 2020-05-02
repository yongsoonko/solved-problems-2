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

int N, M, H, cnt;
int map[31][11];

bool game() {
  for (int col = 1; col <= N; col++) {
    int num = col;
    for (int i = 1; i <= H; i++) {
      if (num < N && map[i][num])
        num++;
      else if (num > 1 && map[i][num - 1])
        num--;
    }
    if (num != col)
      return 0;
  }
  return 1;
}

bool dfs(int pickCnt, int ci, int cj) {
  if (pickCnt == cnt) {
    if (game())
      return 1;
    else
      return 0;
  } else if (ci <= H) {
    for (int i = ci; i <= H; i++)
      for (int j = 1; j < N; j++) {
        if (i == ci && j < cj)
          continue;
        if (map[i][j] == 0) {
          if (j < N - 1 && map[i][j + 1] == 1 ||
              j > 1 && map[i][j - 1] == 1) {
            continue;
          } else {
            map[i][j] = 1;
            int ni = i, nj = j;
            if (nj + 1 == N)
              ni++, nj = 1;
            else
              nj++;
            if (dfs(pickCnt + 1, ni, nj))
              return 1;
            map[i][j] = 0;
          }
        }
      }
    return 0;
    // 아래 else return 0이 없을 때 임의적으로 4를 반환해면서
    // 기대했던 거짓이 아닌 참이 되서 계속 오답이 되었음.
  } else
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> H;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    map[a][b] = 1;
  }

  for (cnt = 0; cnt <= 3; cnt++)
    if (dfs(0, 1, 1)) {
      cout << cnt;
      break;
    }
  if (cnt >= 4)
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}