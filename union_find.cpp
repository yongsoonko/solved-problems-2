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

int root[1001];

int find(int x) {
  if (root[x] == -1)
    return root[x] = x;
  if (root[x] == x)
    return x;

  return root[x] = find(root[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);

  if (x != y)
    root[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  fill(root, root + 1001, -1);

  merge(7, 8);
  cout << find(6) <<'\n';
  cout << find(7) <<'\n';
  cout << find(8) <<'\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}