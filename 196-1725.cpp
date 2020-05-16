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
int A[100001], tree[270000];

int minAns(int ltAns, int rtAns) {
  if (ltAns == 2e9)
    return rtAns;
  if (rtAns == 2e9)
    return ltAns;
  return A[ltAns] < A[rtAns] ? ltAns : rtAns;
}

int init(int node, int start, int end) {
  if (start == end)
    return tree[node] = start;

  int mid = (start + end) / 2;
  return tree[node] = minAns(init(node * 2, start, mid),
                             init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int lt, int rt) {
  if (lt > end || rt < start)
    return 2e9;

  if (lt <= start && end <= rt)
    return tree[node];

  int mid = (start + end) / 2;
  return minAns(query(node * 2, start, mid, lt, rt),
                query(node * 2 + 1, mid + 1, end, lt, rt));
}

int dfs(int lt, int rt) {
  if (lt > rt)
    return -1;
  if (lt == rt)
    return A[lt];

  int m = query(1, 0, N - 1, lt, rt);

  return max(max(dfs(lt, m - 1),
                 dfs(m + 1, rt)),
             (rt - lt + 1) * A[m]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  init(1, 0, N - 1);
  cout << dfs(0, N - 1);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}