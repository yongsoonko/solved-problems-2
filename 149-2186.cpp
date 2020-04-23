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
int N, M, K;
string map[101], word;

// 큐에 추정치 1500만 개 이상 들어가기 때문에 bfs로는 못 풀겠음
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    cin >> map[i];

  cin >> word;

  queue<Pos> Q;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == word[0])
        Q.push({i, j});

  int cnt = 0;
  while (Q.size()) {
    if (cnt + 1 == word.size()) {
      cout << Q.size();
      return 0;
    }

    cnt++;
    int sz = Q.size();
    while (sz--) {
      Pos curr = Q.front();
      Q.pop();

      int ci = curr.i, cj = curr.j;
      for (int j = 1; j <= K; j++)
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i] * j, nj = cj + dj[i] * j;
          if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
              map[ni][nj] == word[cnt])
            Q.push({ni, nj});
        }
    }
  }

  cout << 0;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}