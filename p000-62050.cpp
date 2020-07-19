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
  int k;
  bool operator<(const Pos &p) const {
    return k > p.k;
  }
};

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
bool chk[301][301];

int solution(vector<vector<int>> land, int height) {
  int ans = 0;
  int N = land.size(), M = land[0].size();

  priority_queue<Pos> Q;
  Q.push({0, 0, 0});

  while (Q.size()) {
    int ci = Q.top().i, cj = Q.top().j, ck = Q.top().k;
    Q.pop();

    if (chk[ci][cj])
      continue;

    ans += ck;
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
          !chk[ni][nj]) {
        int diff = abs(land[ci][cj] - land[ni][nj]);
        if (diff > height)
          Q.push({ni, nj, diff});
        else
          Q.push({ni, nj, 0});
      }
    }

    chk[ci][cj] = 1;
  }

  return ans;
}

// 4 4
// 1 4 8 10 5 5 5 5 10 10 10 10 10 10 10 20
// 3
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, M, height;
  cin >> N >> M;
  vector<vector<int>> v(N, vector<int>(M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> v[i][j];
  cin >> height;
  cout << solution(v, height);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}