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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
string map[101];
int dist[101][101];
int N, M;

void bfs() {
  dist[0][0] = 1;

  queue<Pos> q;
  q.push({0, 0});

  while (q.size()) {
    int ci = q.front().i, cj = q.front().j;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
          !dist[ni][nj] && map[ni][nj] == '1') {
        dist[ni][nj] = dist[ci][cj] + 1;
        q.push({ni, nj});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> map[i];

  bfs();
  cout << dist[N - 1][M - 1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}