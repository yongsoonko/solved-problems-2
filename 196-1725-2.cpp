#include <algorithm>
#include <cassert>
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
};

int N;
int A[100001];

int dfs(int lt, int rt) {
  if (lt > rt)
    return -1;
  if (lt == rt)
    return A[lt];

  int mid = (lt + rt) / 2;
  int ret = max(dfs(lt, mid), dfs(mid + 1, rt));

  int p = mid, q = mid + 1,
      w = 2, h = min(A[p], A[q]),
      maxArea = w * h;

  while (p > lt && q < rt) {
    h = A[p - 1] > A[q + 1] ? min(h, A[--p]) : min(h, A[++q]);
    w++;
    maxArea = max(maxArea, w * h);
  }

  while (p > lt) {
    h = min(h, A[--p]);
    w++;
    maxArea = max(maxArea, w * h);
  }

  while (q < rt) {
    h = min(h, A[++q]);
    w++;
    maxArea = max(maxArea, w * h);
  }

  return max(ret, maxArea);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  cout << dfs(0, N - 1);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}