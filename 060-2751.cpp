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

int v[1000001], v2[1000001];

void sort(int lt, int rt) {
  if (lt >= rt)
    return;

  int mid = (lt + rt) / 2;
  sort(lt, mid);
  sort(mid + 1, rt);

  int lo = lt, hi = mid + 1, idx = lt;
  while (lo <= mid && hi <= rt) {
    if (v[lo] < v[hi])
      v2[idx++] = v[lo++];
    else
      v2[idx++] = v[hi++];
  }

  while (lo <= mid)
    v2[idx++] = v[lo++];

  while (hi <= rt)
    v2[idx++] = v[hi++];

  for (int i = lt; i <= rt; i++)
    v[i] = v2[i];
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