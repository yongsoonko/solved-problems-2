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
};

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int seq[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int w, h, ans;
string map[21];
int chk[21][21];
int dist[11][11];
vector<Pos> P;

// *.o.*..........
// .........**....
// .*.............
// ...............
// ...............
// ...............
// x.......*....*.

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
  start:
    cin >> w >> h;
    if (w == 0)
      break;

    ans = 1e9;
    fill(&chk[0][0], &chk[h - 1][w], 0);
    vector<Pos>().swap(P);

    queue<Pos> Q;

    for (int i = 0; i < h; i++) {
      cin >> map[i];
      for (int j = 0; j < w; j++)
        if (map[i][j] == 'o') {
          P.insert(P.begin(), {i, j});
          map[i][j] = '*';
        } else if (map[i][j] == '*')
          P.push_back({i, j});
    }

    for (int i = 0; i < P.size(); i++) {
      fill(&chk[0][0], &chk[h - 1][w], 0);
      chk[P[i].i][P[i].j] = 1;
      Q.push({P[i].i, P[i].j});
      int cnt = 1, step = 0;
      while (Q.size()) {
        step++;
        int sz = Q.size();
        while (sz--) {
          int ci = Q.front().i, cj = Q.front().j;
          Q.pop();
          for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w &&
                !chk[ni][nj] && map[ni][nj] != 'x') {
              if (map[ni][nj] == '*') {
                for (int j = 0; j < P.size(); j++)
                  if (P[j].i == ni && P[j].j == nj) {
                    dist[i][j] = step;
                    break;
                  }
                cnt++;
              }
              chk[ni][nj] = 1;
              Q.push({ni, nj});
            }
          }
        }
        if (cnt == P.size())
          queue<Pos>().swap(Q);
      }
      if (cnt < P.size()) {
        cout << -1 << '\n';
        goto start;
      }
    }
    int sz = P.size() - 1;
    do {
      int sum = dist[0][seq[0]];
      for (int i = 0; i < sz - 1; i++)
        sum += dist[seq[i]][seq[i + 1]];
      ans = min(ans, sum);
    } while (next_permutation(seq, seq + sz));

    cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}