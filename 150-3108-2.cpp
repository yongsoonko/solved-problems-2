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
int N, ans;
int root[1001];
bool chk[1001][1001];
int map[1001][1001];

int find(int x) {
  if (root[x] == -1)
    return root[x] = x;
  if (root[x] == x)
    return x;

  return root[x] = find(root[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);

  if (x != y)
    root[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  fill(root, root + 1001, -1);

  int num = 1;
  int X[2], Y[2];
  for (int i = 0; i < N; i++) {
    cin >> X[0] >> Y[0] >> X[1] >> Y[1];
    X[0] += 500, X[1] += 500, Y[0] += 500, Y[1] += 500;
    for (int j = 0; j < 2; j++)
      for (int k = X[0]; k <= X[1]; k++) {
        if (map[Y[j]][k])
          merge(map[Y[j]][k], num);
        else
          map[Y[j]][k] = num;
      }
    for (int j = 0; j < 2; j++)
      for (int k = Y[0]; k <= Y[1]; k++) {
        if (map[k][X[j]])
          merge(map[k][X[j]], num);
        else
          map[k][X[j]] = num;
      }
    num++;
  }

  if (map[500][500])
    ans--;

  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= 1000; j++)
      if (!chk[i][j] && map[i][j]) {
        ans++;
        chk[i][j] = 1;

        int curr = i * 1001 + j;
        queue<int> Q;
        Q.push(curr);

        while (Q.size()) {
          curr = Q.front();
          Q.pop();

          int ci = (curr / 1001) % 1001, cj = curr % 1001;
          for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni >= 0 && ni < 1001 && nj >= 0 && nj < 1001 &&
                !chk[ni][nj] && find(map[ni][nj]) == find(map[ci][cj])) {
              chk[ni][nj] = 1;
              Q.push(ni * 1001 + nj);
            }
          }
        }
      }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}