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

int N, ans;
int A[500001], tree[2100000];

void update(int node, int start, int end, int num) {
  if (num < start || num > end)
    return;

  if (start == end) {
    ++tree[node];
    return;
  }

  int mid = (start + end) / 2;
  update(2 * node, start, mid, num);
  update(2 * node + 1, mid + 1, end, num);

  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int lt, int rt) {
  if (lt > end || rt < start)
    return 0;

  if (lt <= start && rt >= end)
    return tree[node];

  int mid = (start + end) / 2;
  return query(node * 2, start, mid, lt, rt) +
         query(node * 2 + 1, mid + 1, end, lt, rt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  int mx = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }

  for (int i = 1; i <= N; i++) {
    int res = query(1, 1, mx, A[i] + 1, mx);
    ans = max(ans, res);

    update(1, 1, mx, A[i]);
  }

  cout << ans + 1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}