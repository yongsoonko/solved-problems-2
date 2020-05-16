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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int N, M, ans, cnt;
int A[101][101];
bool chk[101][101];
vector<Pos> C;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      if (A[i][j] == 1)
        C.push_back({i, j});
    }

  while (C.size()) {
    fill(&chk[0][0], &chk[N - 1][M], 0);
    chk[0][0] = 1;
    queue<Pos> Q;
    Q.push({0, 0});

    while (Q.size()) {
      int ci = Q.front().i, cj = Q.front().j;
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
            !chk[ni][nj] && A[ni][nj] == 0) {
          chk[ni][nj] = 1;
          Q.push({ni, nj});
        }
      }
    }

    vector<Pos> v;
    cnt = C.size();
    for (Pos p : C) {
      int i;
      for (i = 0; i < 4; i++) {
        int ni = p.i + di[i], nj = p.j + dj[i];
        if (chk[ni][nj] && A[ni][nj] == 0)
          break;
      }
      if (i == 4)
        v.push_back({p.i, p.j});
      else
        A[p.i][p.j] = 0;
    }
    C.swap(v);
    ans++;
  }

  cout << ans << '\n'
       << cnt;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}