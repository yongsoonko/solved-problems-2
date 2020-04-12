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

int v[1000001];

/**
 * lt : 처음 인덱스
 * rt : 마지막 인덱스(크기 아님)
 */
void sort(int lt, int rt) {
  if (lt >= rt)
    return;
  int hi = rt, ro = lt + 1, pv = v[lt];

  while (ro <= hi) {
    while (ro <= rt && v[ro] <= pv && ro++) {}
    while (hi >= lt + 1 && v[hi] > pv && hi--) {}
    if (ro < hi)
      swap(v[ro], v[hi]);
  }

  swap(v[hi], v[lt]);
  sort(lt, hi - 1);
  sort(hi + 1, rt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> v[i];

  sort(0, N - 1);

  for (int i = 0; i < N; i++)
    cout << v[i] << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}