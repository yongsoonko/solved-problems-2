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
};

int N, M, ans;
int dist[501][501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  fill(&dist[1][1], &dist[N][N + 1], 1e9);

  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  for (int i = 1; i <= N; i++) {
    int gCnt = 0, lCnt = 0;
    for (int j = 1; j <= N; j++)
      if (dist[i][j] < 1e9)
        gCnt++;
      else if (dist[j][i] < 1e9)
        lCnt++;
    if (gCnt + lCnt == N)
      ans++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}