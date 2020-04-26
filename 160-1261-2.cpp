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
  int k;
  bool operator<(const Pos &p) const {
    // 우선순위 큐는 큰 수부터 시작하는 내림차순 정렬이므로
    // 최소힙을 위해 반대로 해야함.
    return k > p.k;
  }
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int N, M;
string map[101];
int dist[101][101];

// 참고 : https://www.crocus.co.kr/546
// 시간복잡도 O(VlogV+ElogV)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  fill(&dist[0][0], &dist[N - 1][M], 1e9);

  for (int i = 0; i < N; i++)
    cin >> map[i];

  dist[0][0] = 0;
  priority_queue<Pos> Q;
  Q.push({0, 0, 0});

  while (Q.size()) {
    int ci = Q.top().i, cj = Q.top().j,
        cost = Q.top().k;
    Q.pop();

    // 다른 곳에서 더 적은 가중치로 바꾼 상태면
    if (dist[ci][cj] < cost)
      continue;

    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
          dist[ni][nj] > cost + map[ni][nj] - '0') {
        dist[ni][nj] = cost + map[ni][nj] - '0';
        // dist[ni][nj] 가 아닌 map[ni][nj] - '0'를 쓰면 안됨.
        Q.push({ni, nj, dist[ni][nj]});
      }
    }
  }
  cout << dist[N - 1][M - 1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}