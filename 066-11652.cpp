#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  ll i;
  int j;
  bool operator<(const Pos &p) const {
    if (j == p.j)
      return i < p.i;
    return j > p.j;
  }
};

ll v[100001];
vector<Pos> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> v[i];

  sort(v, v + N);

  cnt.push_back({v[0], 1});
  for (int i = 1; i < N; i++) {
    if (v[i] == v[i - 1])
      cnt.back().j++;
    else
      cnt.push_back({v[i], 1});
  }

  sort(cnt.begin(), cnt.end());
  cout << cnt.front().i;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}