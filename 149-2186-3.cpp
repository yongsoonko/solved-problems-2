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
int cache[81][101][101];
string map[101], word;

void dfs(int ci, int cj, int cnt) {
  if (cnt == word.size() - 1) {
    cache[cnt][ci][cj] = 1;
    // 같은 위치, 간은 문자열 인덱스일 때 방문한 적이 있다면
    // >로 바꾸면 시간 초과 : 0일 때도 재귀해가는 건 불필요함
  } else if (cache[cnt][ci][cj] >= 0) {
    return;
    // 방문한 적이 없다면
  } else if(cache[cnt][ci][cj] < 0) {
    cache[cnt][ci][cj] = 0; // chk에 방문 표시하는 것과 유사
    for (int j = 1; j <= K; j++)
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i] * j, nj = cj + dj[i] * j;
        if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
            map[ni][nj] == word[cnt + 1]) {
          dfs(ni, nj, cnt + 1);
          cache[cnt][ci][cj] += cache[cnt + 1][ni][nj];
        }
      }
  }
}

// 결국 탑다운 캐싱(메모이제이션) DP로 풀었음.
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
      if (map[i][j] == word[0]) {
        dfs(i, j, 0);
        ans += cache[0][i][j];
      }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}