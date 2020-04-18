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

int N, M;
int A[100001];
Pos tree[270000];

Pos init(int node, int start, int end) {
  if (start == end)
    return tree[node] = {A[start], A[start]};

  int mid = (start + end) / 2;
  Pos a = init(node * 2, start, mid),
      b = init(node * 2 + 1, mid + 1, end);
  return tree[node] = {min(a.i, b.i), max(a.j, b.j)};
}

Pos search(int node, int start, int end, int lt, int rt) {
  if (lt > end || rt < start)
    return {(int)2e9, 0};

  if (lt <= start && rt >= end)
    return tree[node];

  if (start != end) {
    int mid = (start + end) / 2;
    Pos a = search(node * 2, start, mid, lt, rt),
        b = search(node * 2 + 1, mid + 1, end, lt, rt);
    return {min(a.i, b.i), max(a.j, b.j)};
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
    cin >> A[i];

  init(1, 1, N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    Pos p = search(1, 1, N, a, b);
    cout << p.i << ' ' << p.j << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}