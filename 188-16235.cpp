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

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
int A[11][11], S[11][11], Y[11][11];
deque<int> T[11][11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  fill(&S[0][0], &S[N - 1][N], 5);

  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    T[x][y].push_back(z);
  }

  for (int cnt = 0; cnt < K; cnt++) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        int died = 0;
        deque<int> v;
        for (int k : T[i][j]) {
          if (S[i][j] - k >= 0) {
            S[i][j] -= k;
            v.push_back(k + 1);
            if ((k + 1) % 5 == 0)
              Y[i][j]++;
          } else
            died += k / 2;
        }
        T[i][j].swap(v);
        S[i][j] += died;
      }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        while (Y[i][j]) {
          for (int d = 0; d < 8; d++) {
            int ni = i + di[d], nj = j + dj[d];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N)
              T[ni][nj].push_front(1);
          }
          Y[i][j]--;
        }
        S[i][j] += A[i][j];
      }
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      ans += T[i][j].size();

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}