#include <algorithm>
#include <cmath>
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

int N, M, K, sz;
ll A[1000001], tree[2100000];

ll init(int node, int start, int end) {
  if (start == end)
    return tree[node] = A[start];

  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) +
                      init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int lt, int rt) {
  if (lt > end || rt < start)
    return 0;

  if (lt <= start && rt >= end)
    return tree[node];

  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, lt, rt) +
         sum(node * 2 + 1, mid + 1, end, lt, rt);
}

void update(int node, int start, int end, int idx, ll diff) {
  if (idx < start || idx > end)
    return;

  tree[node] += diff;

  if (start != end) {
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
  } else
    tree[node] = A[start];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;

  int h = ceil(log2(N));
  sz = (1 << (h + 1));

  for (int i = 1; i <= N; i++)
    cin >> A[i];

  init(1, 1, N);

  for (int i = 0; i < M + K; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      ll diff = c - A[b];
      A[b] = c;
      update(1, 1, N, b, diff);
    } else if (a == 2)
      cout << sum(1, 1, N, b, c) << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}