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
int M, N, K;
vector<int> S;
int map[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N >> K;

  for (int k = 0; k < K; k++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
      for (int j = y1; j < y2; j++)
        map[i][j] = 1;
  }

  queue<Pos> Q;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 0) {
        int square = 0;
        map[i][j] = 1;
        Q.push({i, j});
        while (Q.size()) {
          int ci = Q.front().i, cj = Q.front().j;
          Q.pop();
          square++;
          for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
                map[ni][nj] == 0) {
              map[ni][nj] = 1;
              Q.push({ni, nj});
            }
          }
        }
        S.push_back(square);
      }

  sort(S.begin(), S.end());
  cout << S.size() << '\n';
  for (int i : S)
    cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}