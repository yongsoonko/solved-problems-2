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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int R, C;
string map[501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C;

  for (int i = 0; i < R; i++)
    cin >> map[i];

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (map[i][j] == 'S')
        for (int k = 0; k < 4; k++) {
          int ni = i + di[k], nj = j + dj[k];
          if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
            if (map[ni][nj] == 'W') {
              cout << 0;
              return 0;
            } else if (map[ni][nj] == '.')
              map[ni][nj] = 'D';
          }
        }

  cout << 1 << '\n';
  for (int i = 0; i < R; i++)
    cout << map[i] << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}