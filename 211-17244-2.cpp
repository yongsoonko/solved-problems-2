#include <algorithm>
#include <cassert>
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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int N, M;
string A[51];
bool chk[51][51];
int dist[8][8];
int seq[] = {1, 2, 3, 4, 5};
vector<Pos> P;

void bfs(int idx) {
  int si = P[idx].i, sj = P[idx].j;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  Pos E;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 'X')
        P.push_back({i, j});
      else if (A[i][j] == 'S') {
        P.insert(P.begin(), {i, j});
        A[i][j] = '.';
      } else if (A[i][j] == 'E')
        E = {i, j};
    }
  }
  P.push_back(E);

  for (int idx = 0; idx < P.size() - 1; idx++) {
    fill(&chk[0][0], &chk[N - 1][M], 0);
    queue<Pos> Q;
    chk[P[idx].i][P[idx].j] = 1;
    Q.push({P[idx].i, P[idx].j});
    int cnt = 0, move = 0;
    while (Q.size()) {
      move++;
      int sz = Q.size();
      while (sz--) {
        int ci = Q.front().i, cj = Q.front().j;
        Q.pop();
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
              !chk[ni][nj] && A[ni][nj] != '#') {
            chk[ni][nj] = 1;
            Q.push({ni, nj});
            if (A[ni][nj] == 'X' || A[ni][nj] == 'E')
              for (int j = 0; j < P.size(); j++) {
                Pos p = P[j];
                if (ni == p.i && nj == p.j) {
                  dist[idx][j] = move;
                  cnt++;
                }
              }
          }
        }
      }
      // 현위치 제외
      if (cnt == P.size() - 1)
        break;
    }
  }

  int ans = 1e9, xCnt = P.size() - 2;
  if (xCnt == 0) {
    cout << dist[0][P.size() - 1];
    return 0;
  }

  do {
    int sum = dist[0][seq[0]];
    for (int i = 0; i < xCnt - 1; i++)
      sum += dist[seq[i]][seq[i + 1]];
    assert(xCnt - 1 >= 0);
    sum += dist[seq[xCnt - 1]][P.size() - 1];
    ans = min(ans, sum);
  } while (next_permutation(seq, seq + xCnt));

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}