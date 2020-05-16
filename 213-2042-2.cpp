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

int N, M, K;
ll A[1000001], tree[2100000];

ll init(int node, int start, int end) {
  if (start == end)
    return tree[node] = A[start];

  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) +
                      init(node * 2 + 1, mid + 1, end);
}

// lt, rt : 찾고자 하는 범위
ll query(int node, int start, int end, int lt, int rt) {
  // 하나도 포함하지 않음
  if (rt < start || lt > end)
    return 0;
  // 완전히 포함함
  if (lt <= start && end <= rt)
    return tree[node];
  // 일부만 겹침
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, lt, rt) +
         query(node * 2 + 1, mid + 1, end, lt, rt);
}

void update(int node, int start, int end, int idx, ll diff) {
  if (start <= idx && idx <= end) {
    tree[node] += diff;

    if (start != end) {
      int mid = (start + end) / 2;
      update(node * 2, start, mid, idx, diff);
      update(node * 2 + 1, mid + 1, end, idx, diff);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    cin >> A[i];

  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, 1, N, b, c - A[b]);
      A[b] = c;
    } else if (a == 2)
      cout << query(1, 1, N, b, c) << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}