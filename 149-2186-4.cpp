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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int cache[81][101][101];
int N, M, K, ans;
string map[101], word;

void dfs(int ci, int cj, int cnt) {
  if (cnt == 0) {
    cache[0][ci][cj] = 1;
  } else if (cache[cnt][ci][cj] < 0) {
    cache[cnt][ci][cj] = 0;
    for (int j = 1; j <= K; j++)
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i] * j, nj = cj + dj[i] * j;
        if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
            map[ni][nj] == word[cnt - 1]) {
          dfs(ni, nj, cnt - 1);
          cache[cnt][ci][cj] += cache[cnt - 1][ni][nj];
        }
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    cin >> map[i];

  cin >> word;

  fill(&cache[0][0][0], &cache[80][100][101], -1);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == word.back()) {
        dfs(i, j, word.size() - 1);
        ans += cache[word.size() - 1][i][j];
      }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}