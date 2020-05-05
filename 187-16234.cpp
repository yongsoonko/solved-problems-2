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
  int k;
};

int N, L, R;
int A[51][51];
Pos root[51][51];

int find(int x) {
  int ci = x / 51, cj = x % 51;
  if (root[ci][cj].i == -1) {
    root[ci][cj] = {x, A[ci][cj], 1};
    return x;
  }
  if (root[ci][cj].i == x)
    return x;
  int nx = find(root[ci][cj].i);
  root[ci][cj] = root[nx / 51][nx % 51];
  return nx;
}

void merge(int x, int y) {
  x = find(x), y = find(y);

  if (x != y) {
    int xi = x / 51, xj = x % 51,
        yi = y / 51, yj = y % 51;
    root[xi][xj].i = y;
    root[yi][yj].j += root[xi][xj].j;
    root[yi][yj].k += root[xi][xj].k;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  for (int ans = 0; ans <= 2000; ans++) {
    bool flag = 1;
    fill(&root[0][0], &root[N - 1][N], Pos({-1, 0, 0}));

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        if (j + 1 < N) {
          int diff = abs(A[i][j] - A[i][j + 1]);
          if (L <= diff && diff <= R) {
            merge(i * 51 + j, i * 51 + j + 1);
            flag = 0;
          }
        }
        if (i + 1 < N) {
          int diff = abs(A[i][j] - A[i + 1][j]);
          if (L <= diff && diff <= R) {
            merge(i * 51 + j, (i + 1) * 51 + j);
            flag = 0;
          }
        }
      }
    if (flag) {
      cout << ans;
      return 0;
    }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        int x = find(i * 51 + j),
            xi = x / 51, xj = x % 51;
        A[i][j] = root[xi][xj].j / root[xi][xj].k;
      }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}