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

int N, S, D, ans;
vector<Pos> E[100001];
bool chk[100001];

void dfs(int curr, int add, int maxi) {
  if (curr == D) {
    ans = add - maxi;
  } else {
    chk[curr] = 1;
    for (Pos p : E[curr])
      if (!chk[p.i])
        dfs(p.i, add + p.j, max(maxi, p.j));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S >> D;
  for (int i = 1; i < N; i++) {
    int s, d, v;
    cin >> s >> d >> v;
    E[s].push_back({d, v});
    E[d].push_back({s, v});
  }

  dfs(S, 0, 0);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}