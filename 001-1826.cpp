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
  bool operator<(const Pos &p) const {
    return i < p.i;
  }
};

int N, L, P;
vector<Pos> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  cin >> L >> P;
  v.push_back({L, 0});

  int ans = 0, dist = 0;
  priority_queue<int> pq;
  for (int i = 0; i < v.size(); i++) {
    while (P - (v[i].i - dist) < 0) {
      if (pq.size()) {
        P += pq.top();
        pq.pop();
        ans++;
      } else {
        cout << -1;
        return 0;
      }
    }
    P -= v[i].i - dist;
    dist = v[i].i;
    if (dist == L) {
      cout << ans;
      return 0;
    }
    pq.push(v[i].j);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}