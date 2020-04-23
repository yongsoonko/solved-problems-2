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
bool map[2001][2001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 = (x1 + 500) * 2;
    y1 = (y1 + 500) * 2;
    x2 = (x2 + 500) * 2;
    y2 = (y2 + 500) * 2;
    for (int j = x1; j <= x2; j++)
      map[y1][j] = map[y2][j] = 1;
    for (int j = y1; j <= y2; j++)
      map[j][x1] = map[j][x2] = 1;
  }

  if (map[1000][1000])
    ans--;

  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= 2000; j++)
      if (map[i][j]) {
        ans++;
        map[i][j] = 0;

        int curr = i * 2001 + j;
        queue<int> Q;
        Q.push(curr);

        while (Q.size()) {
          curr = Q.front();
          Q.pop();

          int ci = (curr / 2001) % 2001, cj = curr % 2001;
          for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni >= 0 && ni < 2001 && nj >= 0 && nj < 2001 &&
                map[ni][nj]) {
              map[ni][nj] = 0;
              Q.push(ni * 2001 + nj);
            }
          }
        }
      }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}