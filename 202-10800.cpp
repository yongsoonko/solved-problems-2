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
  int c;
  int s;
};

bool comp(Pos a, Pos b) {
  return a.s < b.s;
}

int N, aSum, cSum[200001], ans[200001];
vector<Pos> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    int c, s;
    cin >> c >> s;
    P.push_back({i, c, s});
  }

  sort(P.begin(), P.end(), comp);

  int p = 0, q = 0;
  while (p < P.size()) {
    if (P[p].s == P[q].s) {
      ans[P[q].i] = aSum - cSum[P[q].c];
      q++;
    } else {
      aSum += P[p].s;
      cSum[P[p].c] += P[p].s;
      p++;
    }
  }

  for (int i = 0; i < N; i++)
    cout << ans[i] << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}