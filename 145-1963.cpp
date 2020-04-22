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

int T, A, B;
int dist[10000];
int prime[10000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  fill(prime, prime + 10000, 1);
  prime[1] = 0;
  for (int i = 2; i * i <= 9999; i++) {
    if (prime[i])
      for (int j = i + i; j <= 9999; j += i)
        prime[j] = 0;
  }

  cin >> T;

  while (T--) {
    cin >> A >> B;

    fill(dist, dist + 10000, 0);
    dist[A] = 1;
    queue<int> Q;
    Q.push(A);

    while (Q.size()) {
      int sz = Q.size();
      while (sz--) {
        int curr = Q.front();
        Q.pop();

        for (int i = 1000; i >= 1; i /= 10) {
          int num = curr - ((curr / i) % 10) * i;
          for (int j = 0; j <= 9; j++) {
            int next = num + i * j;
            if (next >= 1000 && next <= 9999 &&
                prime[next] && !dist[next]) {
              dist[next] = dist[curr] + 1;
              Q.push(next);
            }
          }
        }
      }
      if (dist[B])
        break;
    }
    cout << dist[B] - 1 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}