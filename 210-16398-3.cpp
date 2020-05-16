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
  bool operator<(const Pos &p) const {
    return j > p.j;
  }
};

int N;
vector<Pos> E[1001];
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
      E[i].push_back({j, a});
      E[j].push_back({i, a});
    }

  // O(ElogV) 400ms
  priority_queue<Pos> Q;
  Q.push({0, 0});

  while (Q.size()) {
    int curr = Q.top().i, w = Q.top().j;
    Q.pop();

    if (chk[curr])
      continue;

    for (Pos next : E[curr])
      if (!chk[next.i])
        Q.push(next);

    ans += w;
    chk[curr] = 1;
  }

  // O(VE)  시간초과
  // chk[0] = 1;
  // for (int cnt = 0; cnt < N - 1; cnt++) {
  //   int minIdx, min = 1e9;
  //   for (int i = 0; i < N; i++)
  //     if (chk[i])
  //       for (Pos p : E[i])
  //         if (!chk[p.i] && min > p.j) {
  //           min = p.j;
  //           minIdx = p.i;
  //         }

  //   ans += min;
  //   chk[minIdx] = 1;
  // }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}