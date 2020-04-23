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
int N, M, K, ans;
string map[101], word;

void dfs(int ci, int cj, int cnt) {
  if (cnt == word.size()) {
    ans++;
  } else {
    for (int j = 1; j <= K; j++)
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i] * j, nj = cj + dj[i] * j;
        if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
            map[ni][nj] == word[cnt])
          dfs(ni, nj, cnt + 1);
      }
  }
}

// dfs 역시 마찬가지로 시간 초과가 발생함. 결국 재귀DP로 풀이해야함
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    cin >> map[i];

  cin >> word;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == word[0])
        dfs(i, j, 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}