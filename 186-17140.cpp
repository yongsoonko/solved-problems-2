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
  bool operator<(const Pos &p) const {
    if (j == p.j)
      return i < p.i;
    return j < p.j;
  }
};

int r, c, k;
int map[101][101];
Pos num[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  fill(num, num + 101, Pos({0, 200}));

  cin >> r >> c >> k;
  r--, c--;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> map[i][j];

  int rCnt = 3, cCnt = 3;
  for (int sec = 0; sec <= 100; sec++) {
    if (map[r][c] == k) {
      cout << sec;
      return 0;
    }
    if (rCnt >= cCnt) {
      int cMax = 0;
      for (int i = 0; i < rCnt; i++) {
        for (int j = 0; j < cCnt; j++)
          if (map[i][j]) {
            num[map[i][j]].i = map[i][j];
            if (num[map[i][j]].j == 200)
              num[map[i][j]].j = 1;
            else
              num[map[i][j]].j++;
          }

        sort(num, num + 101);
        for (int j = 0; j < 50; j++) {
          if (num[j].j == 200) {
            while (j < 50) {
              map[i][j * 2] = map[i][j * 2 + 1] = 0;
              j++;
            }
            break;
          }
          cMax = max(cMax, (j + 1) * 2);
          map[i][j * 2] = num[j].i;
          map[i][j * 2 + 1] = num[j].j;
        }
        fill(num, num + 101, Pos({0, 200}));
      }
      cCnt = cMax;
    } else {
      int rMax = 0;
      for (int i = 0; i < cCnt; i++) {
        for (int j = 0; j < rCnt; j++) {
          if (map[j][i]) {
            num[map[j][i]].i = map[j][i];
            if (num[map[j][i]].j == 200)
              num[map[j][i]].j = 1;
            else
              num[map[j][i]].j++;
          }
        }
        sort(num, num + 101);
        for (int j = 0; j < 50; j++) {
          if (num[j].j == 200) {
            while (j < 50) {
              map[j * 2][i] = map[j * 2 + 1][i] = 0;
              j++;
            }
            break;
          }
          rMax = max(rMax, (j + 1) * 2);
          map[j * 2][i] = num[j].i;
          map[j * 2 + 1][i] = num[j].j;
        }
        fill(num, num + 101, Pos({0, 200}));
      }
      rCnt = rMax;
    }
  }
  cout << -1 << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}