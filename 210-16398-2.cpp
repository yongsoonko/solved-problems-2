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
  int k;
  bool operator<(const Pos &p) const {
    return k > p.k;
  }
};

int N;
int E[1001][1001];
bool chk[1001];
ll ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      E[i][j] = a;
    }

  // 가장 최적화됨  148ms
  chk[0] = 1;
  priority_queue<Pos> Q;
  for (int i = 1; i < N; i++)
    Q.push({i, E[0][i]});

  for (int cnt = 1; cnt < N; cnt++) {
    Pos p;
    do {
      p = Q.top();
      Q.pop();
    } while (chk[p.i]);

    for (int i = 0; i < N; i++)
      if (E[p.i][i] && !chk[i])
        Q.push({i, E[p.i][i]});

    ans += p.k;
    chk[p.i] = 1;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}