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

int N;
int dist[51][51], score[51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  fill(&dist[1][1], &dist[N][N + 1], 1e9);
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;

  while (1) {
    int a, b;
    cin >> a >> b;
    if (a == -1)
      break;

    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  int mini = 1e9;
  vector<int> ans;
  for (int i = 1; i <= N; i++) {
    int maxi = 0;
    for (int j = 1; j <= N; j++)
      maxi = max(maxi, dist[i][j]);
    if (mini >= maxi) {
      if (mini > maxi) {
        vector<int>().swap(ans);
        mini = maxi;
      }
      ans.push_back(i);
    }
  }

  cout << mini << ' ' << ans.size() << '\n';
  for (int i : ans)
    cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}