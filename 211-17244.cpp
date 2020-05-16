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
  int k;
};

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int N, M, ans, E;
string A[51];
bool chk[51][51][32];
vector<Pos> X;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;

  queue<Pos> Q;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 'X')
        X.push_back({i, j});
      else if (A[i][j] == 'S') {
        chk[i][j][0] = 1;
        Q.push({i, j, 0});
        A[i][j] = '.';
      }
    }
  }
  E = (1 << X.size()) - 1;

  int flag = 0;
  while (Q.size()) {
    int sz = Q.size();
    while (sz--) {
      int ci = Q.front().i, cj = Q.front().j, ck = Q.front().k;
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i], nk;
        if (A[ni][nj] == 'X') {
          int j;
          for (j = 0; j < X.size(); j++) {
            Pos p = X[j];
            if (ni == p.i && nj == p.j)
              break;
          }
          if (!(ck & (1 << j))) {
            nk = ck + (1 << j);
            chk[ni][nj][nk] = 1;
            Q.push({ni, nj, nk});
          } else if (!chk[ni][nj][ck]) {
            chk[ni][nj][ck] = 1;
            Q.push({ni, nj, ck});
          }
        } else if (A[ni][nj] == '.' && !chk[ni][nj][ck]) {
          chk[ni][nj][ck] = 1;
          Q.push({ni, nj, ck});
        } else if (A[ni][nj] == 'E' && ck == E)
          flag = 1;
      }
    }
    ans++;
    if (flag) {
      cout << ans;
      return 0;
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}