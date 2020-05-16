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
  int k;
  bool operator<(const Pos &p) const {
    return k > p.k;
  }
};

int root[1001];

int find(int x) {
  if (root[x] == -1)
    return root[x] = x;
  if (root[x] == x)
    return x;
  return root[x] = find(root[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);

  if (x != y)
    root[x] = y;
}

int N;
ll ans;
vector<Pos> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  fill(root, root + N, -1);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      if (i < j)
        E.push_back({i, j, a});
    }

  sort(E.begin(), E.end());

  for (int cnt = 1; cnt < N; cnt++) {
    Pos p;
    do {
      p = E.back();
      E.pop_back();
    } while (find(p.i) == find(p.j));
    merge(p.i, p.j);
    ans += (ll)p.k;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}