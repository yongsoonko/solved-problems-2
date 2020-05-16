#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int N, M;
int chk[101], dist[101][101];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  fill(&dist[1][1], &dist[N][N + 1], 1e9);
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  for (int i = 1; i <= N; i++) {
    set<int> S;
    if (!chk[i]) {
      for (int j = 1; j <= N; j++)
        if (dist[i][j] < 1e9) {
          chk[j] = 1;
          S.insert(j);
        }
      int mini = 1e9, minii;
      for (int j : S) {
        int maxi = -1;
        for (int k : S)
          if (maxi < dist[j][k])
            maxi = dist[j][k];
        if (mini > maxi) {
          mini = maxi;
          minii = j;
        }
      }
      ans.push_back(minii);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i : ans)
    cout << i << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}