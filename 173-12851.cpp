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

int N, K;
int dist[100001];
int cnt[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> K;

  cnt[N] = 1;
  queue<int> Q;
  Q.push(N);

  while (Q.size()) {
    if (dist[K])
      break;
    int sz = Q.size();
    while (sz--) {
      int curr = Q.front();
      Q.pop();

      for (int next : {curr - 1, curr + 1, curr * 2})
        if (next >= 0 && next <= 100000 && !cnt[next]) {
          dist[next] = dist[curr] + 1;
          Q.push(next);
        }
    }
    // 하나의 레벨이 끝나고 나서야 방문 체크를 한다.
    sz = Q.size();
    while (sz--) {
      int next = Q.front();
      Q.pop();
      cnt[next]++;
      Q.push(next);
    }
  }

  cout << dist[K] << '\n'
       << cnt[K];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}