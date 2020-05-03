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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int N, M, cnt;
string map[11];
int chk[11][11][11][11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  int cri, crj, cbi, cbj;
  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 'R') {
        cri = i, crj = j;
        map[i][j] = '.';
      } else if (map[i][j] == 'B') {
        cbi = i, cbj = j;
        map[i][j] = '.';
      }
    }
  }

  queue<int> Q;
  chk[cri][crj][cbi][cbj] = 1;
  Q.push(cri * 1000 + crj * 100 + cbi * 10 + cbj);

  while (Q.size()) {
    cnt++;
    int sz = Q.size();
    while (sz--) {
      cri = Q.front() / 1000, crj = Q.front() / 100 % 10,
      cbi = Q.front() / 10 % 10, cbj = Q.front() % 10;
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int nri = cri, nrj = crj,
            nbi = cbi, nbj = cbj,
            outR = 0, outB = 0;
        while (map[nri + di[i]][nrj + dj[i]] != '#') {
          if (map[nri + di[i]][nrj + dj[i]] == 'O') {
            outR = 1;
            break;
          }
          nri += di[i], nrj += dj[i];
        }
        while (map[nbi + di[i]][nbj + dj[i]] != '#') {
          if (map[nbi + di[i]][nbj + dj[i]] == 'O') {
            outB = 1;
            break;
          }
          nbi += di[i], nbj += dj[i];
        }
        if (outB)
          continue;
        else if (outR) {
          cout << cnt;
          return 0;
        } else {
          if (nri == nbi && nrj == nbj) {
            if (i == 0) {
              if (cri < cbi)
                nbi++;
              else
                nri++;
            } else if (i == 1) {
              if (crj < cbj)
                nrj--;
              else
                nbj--;
            } else if (i == 2) {
              if (cri < cbi)
                nri--;
              else
                nbi--;
            } else {
              if (crj < cbj)
                nbj++;
              else
                nrj++;
            }
          }
          if (chk[nri][nrj][nbi][nbj] == 0) {
            chk[nri][nrj][nbi][nbj] = 1;
            Q.push(nri * 1000 + nrj * 100 + nbi * 10 + nbj);
          }
        }
      }
    }
  }
  cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}