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

string D = "UDLR";
int R, C;
int map[1001][1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> R >> C;

  int min = 1001, mi, mj;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];
      if ((i + j) % 2 && min > map[i][j]) {
        min = map[i][j];
        mi = i;
        mj = j;
      }
    }

  if (R % 2) {
    int d = 3, ci = 0, cj = 0;
    while (1) {
      if (d == 3 && cj == C - 1) {
        if (ci < R - 1) {
          cout << D[1];
          ci++;
          d = 2;
        } else
          break;
      } else if (d == 2 && cj == 0) {
        cout << D[1];
        ci++;
        d = 3;
      } else {
        cout << D[d];
        if (d == 2)
          cj--;
        else
          cj++;
      }
    }
  } else if (C % 2) {
    int d = 1, ci = 0, cj = 0;
    while (1) {
      if (d == 1 && ci == R - 1) {
        if (cj < C - 1) {
          cout << D[3];
          cj++;
          d = 0;
        } else
          break;
      } else if (d == 0 && ci == 0) {
        cout << D[3];
        cj++;
        d = 1;
      } else {
        cout << D[d];
        if (d == 0)
          ci--;
        else if (d == 1)
          ci++;
      }
    }
  } else {
    int d = 3, ci = 0, cj = 0;
    while (1) {
      if (ci == (mi / 2) * 2 && cj == 0) {
        d = 3;
        break;
      } else if (d == 3 && cj == C - 1) {
        cout << D[1];
        ci++;
        d = 2;
      } else if (d == 2 && cj == 0) {
        cout << D[1];
        ci++;
        d = 3;
      } else {
        cout << D[d];
        if (d == 2)
          cj--;
        if (d == 3)
          cj++;
      }
    }

    d = 1;
    int d2 = 3;
    while (1) {
      if (cj == C - 1) {
        if (ci < R - 1) {
          cout << D[1];
          ci++;
        }
        break;
      } else if (d == 1 && ci + 1 == mi && cj == mj) {
        swap(d, d2);
      } else if (d == 0 && ci - 1 == mi && cj == mj) {
        swap(d, d2);
      }

      cout << D[d] << D[d2];
      if (d == 0) {
        ci--;
        d = 1;
      } else if (d == 1) {
        ci++;
        d = 0;
      }
      if (d2 == 0) {
        ci--;
        d2 = 1;
      } else if (d2 == 1) {
        ci++;
        d2 = 0;
      }

      cj++;
    }

    d = 2;
    while (1) {
      if (ci == R - 1 && cj == C - 1) {
        break;
      } else if (d == 2 && cj == 0) {
        cout << D[1];
        ci++;
        d = 3;
      } else if (d == 3 && cj == C - 1) {
        cout << D[1];
        ci++;
        d = 2;
      } else {
        cout << D[d];
        if (d == 2)
          cj--;
        else if (d == 3)
          cj++;
      }
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}