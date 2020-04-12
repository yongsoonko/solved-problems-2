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

// 참고 : https://www.crocus.co.kr/648
class segtree {
  int *data;
  int size;

public:
  segtree(int *v, int sz) {
    int h = ceil(log2(sz));
    size = 1 << (h + 1);
    data = new int[size];

    init(v, 1, 0, sz - 1);
  }
  int init(int *v, int node, int start, int end) {
    if (start == end)
      return data[node] = v[start];

    int mid = (start + end) / 2;
    return data[node] = init(v, node * 2, start, mid) +
                        init(v, node * 2 + 1, mid + 1, end);
  }
  void update(int *v, int sz, int idx, int val) {
    update(1, 0, sz - 1, idx, val - v[idx]);
    v[idx] = val;
  }
  void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end)
      return;

    int mid = (start + end) / 2;
    if (start != end) {
      data[node] += diff;
      update(node * 2, start, mid, idx, diff);
      update(node * 2 + 1, mid + 1, end, idx, diff);
    }
  }
  int sum(int sz, int lt, int rt) {
    return sum(1, 0, sz - 1, lt, rt);
  }
  int sum(int node, int start, int end, int lt, int rt) {
    if (rt < start || lt > end)
      return 0;

    if (lt <= start && rt >= end)
      return data[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, lt, rt) +
           sum(node * 2 + 1, mid + 1, end, lt, rt);
  }
  void print() {
    for (int i = 1; i < size; i++)
      cout << data[i] << ' ';
    cout << '\n';
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int v[12] = {3, 5, 6, 7, 2, 9, 4, 5, 2, 8, 1, 5};
  segtree tree(v, 12);
  tree.print();

  // 뒤의 두 인수는 각각 인덱스와 바꿀 값
  tree.update(v, 12, 4, 10);
  tree.print();

  cout << tree.sum(12, 0, 3);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}