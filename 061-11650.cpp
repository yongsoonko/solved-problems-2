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
    if (i == p.i)
      return j < p.j;
    return i < p.i;
  }
};

Pos p[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> p[i].i >> p[i].j;

  sort(p, p + N);

  for (int i = 0; i < N; i++)
    cout << p[i].i << ' ' << p[i].j << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}