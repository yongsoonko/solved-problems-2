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
int N, M;
string map[101];
int dist[101][101];

// 엄밀히 말하면 다익스트라 알고리즘이 아님.
// 다익스트라 알고리즘은 프림 MST 알고리즘과 유사함.
// 재귀가 없음.
void dfs(int ci, int cj) {
  if (ci == N - 1 && cj == M - 1)
    return;

  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
        dist[ni][nj] > dist[ci][cj] + map[ni][nj] - '0') {
      dist[ni][nj] = dist[ci][cj] + map[ni][nj] - '0';
      dfs(ni, nj);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  fill(&dist[0][0], &dist[N - 1][M], 1e9);

  for (int i = 0; i < N; i++)
    cin >> map[i];

  dist[0][0] = 0;
  dfs(0, 0);

  cout << dist[N - 1][M - 1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}