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
int A[100001], tree[270000];

int init(int node, int start, int end) {
  if (start == end)
    return tree[node] = A[start];

  int mid = (start + end) / 2;
  return tree[node] = min(init(node * 2, start, mid),
                          init(node * 2 + 1, mid + 1, end));
}

int search(int node, int start, int end, int lt, int rt) {
  if (lt > end || rt < start)
    return 2e9;

  if (lt <= start && rt >= end)
    return tree[node];

  if (start != end) {
    int mid = (start + end) / 2;
    return min(search(node * 2, start, mid, lt, rt),
               search(node * 2 + 1, mid + 1, end, lt, rt));
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
    cout << search(1, 1, N, a, b) << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}