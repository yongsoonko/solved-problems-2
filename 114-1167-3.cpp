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

vector<Pos> E[100001];
int chk[100001];
int V, ans;

int dfs(int curr) {
  chk[curr] = 1;

  int fi = 0, se = 0;
  for (Pos next : E[curr]) {
    if (!chk[next.i]) {
      int tmp = next.j + dfs(next.i);
      if (fi < tmp) {
        se = fi;
        fi = tmp;
      } else if (se < tmp)
        se = tmp;
    }
  }
  ans = max(ans, fi + se);
  return fi;
}

// 참고 : https://www.acmicpc.net/source/681283
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> V;

  for (int i = 1; i <= V; i++) {
    int a, b, c;
    cin >> a;
    while (1) {
      cin >> b;
      if (b == -1)
        break;
      cin >> c;
      E[a].push_back({b, c});
    }
  }

  dfs(1);
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}