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

int R, C;
int map[1001][1001];

void moveHorizontal(int row, int col, int ff) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col - 1; j++) {
      if (ff)
        cout << 'R';
      else
        cout << 'L';
    }
    if (i < row - 1)
      cout << 'D';
    ff = not ff;
  }
}

void moveVertical(int row, int col) {
  int ff = 1;
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row - 1; j++) {
      if (ff)
        cout << 'D';
      else
        cout << 'U';
    }
    if (i < col - 1)
      cout << 'R';
    ff = not ff;
  }
}

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
    moveHorizontal(R, C, 1);
  } else if (C % 2) {
    moveVertical(R, C);
  } else {
    int ni = (mi / 2) * 2;
    moveHorizontal(ni, C, 1);
    if (ni >= 2)
      cout << 'D';
    int ff = 1;
    string way = "DR", way2 = "UR";
    for (int j = 0; j < C - 1; j++) {
      if (j == mj)
        way = "RD", way2 = "RU";
      if (ff)
        cout << way;
      else
        cout << way2;
      ff = not ff;
    }
    if (ni < ((R - 1) / 2) * 2) {
      cout << 'D';
      moveHorizontal(R - 2 - ni, C, 0);
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}