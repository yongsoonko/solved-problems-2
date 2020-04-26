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
int chk[101][101];
int dist[101][101];

// 참고 : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// 시간복잡도 O(V^2 + E)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  fill(&dist[0][0], &dist[N - 1][M], 1e9);

  for (int i = 0; i < N; i++)
    cin >> map[i];

  dist[0][0] = 0;

  int V = N * M - 1;
  for (int cnt = 0; cnt < V; cnt++) {
    // 방문하지 않은 곳 중 시작점에서부터 거리를 기준으로
    // 가장 가까운 곳을 구함.
    int min = 2e9, mini, minj;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (!chk[i][j] && min > dist[i][j]) {
          min = dist[i][j];
          mini = i, minj = j;
        }

    // 찾은 곳을 기준 인접한 곳으로의 dist배열을 갱신
    for (int i = 0; i < 4; i++) {
      int ni = mini + di[i], nj = minj + dj[i];
      if (ni >= 0 && ni < N && nj >= 0 && nj < M && !chk[ni][nj] &&
          dist[ni][nj] > dist[mini][minj] + map[ni][nj] - '0')
        dist[ni][nj] = dist[mini][minj] + map[ni][nj] - '0';
    }

    // 현재 지점 방문 표시
    chk[mini][minj] = 1;
  }

  cout << dist[N - 1][M - 1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}