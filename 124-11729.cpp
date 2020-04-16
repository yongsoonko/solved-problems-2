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

vector<Pos> v;

void dfs(int curr, int from, int tmp, int to) {
  if (curr == 0)
    return;

  dfs(curr - 1, from, to, tmp);
  v.push_back({from, to});
  dfs(curr - 1, tmp, from, to);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  dfs(N, 1, 2, 3);

  cout << v.size() << '\n';
  for (Pos p : v)
    cout << p.i << ' ' << p.j << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}