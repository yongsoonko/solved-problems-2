#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  short x1;
  short y1;
  short x2;
  short y2;
};

int N, ans;
int root[1001];
Pos P[1001];

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

bool cross(Pos &t, Pos &u) {
  // 좌우로 떨어져 있거나
  if (t.x2 < u.x1 || t.x1 > u.x2)
    return 0;
  // 상하로 떨어져 있거나
  if (t.y2 < u.y1 || t.y1 > u.y2)
    return 0;
  // t가 u에 안에 있거나
  if (u.x1 < t.x1 && t.x2 < u.x2 &&
      u.y1 < t.y1 && t.y2 < u.y2)
    return 0;
  // u가 t에 안에 있거나
  if (t.x1 < u.x1 && u.x2 < t.x2 &&
      t.y1 < u.y1 && u.y2 < t.y2)
    return 0;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  fill(root, root + 1001, -1);

  bool once = 1;
  for (int i = 1; i <= N; i++) {
    short x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    P[i] = {x1, y1, x2, y2};
    if (once && ((x1 <= 0 && 0 <= x2 && (y1 == 0 || y2 == 0)) ||
                 (y1 <= 0 && 0 <= y2 && (x1 == 0 || x2 == 0)))) {
      once = 0;
      ans--;
    }
    find(i);
  }

  for (int i = 1; i < N; i++)
    for (int j = i + 1; j <= N; j++)
      if (cross(P[i], P[j]))
        merge(i, j);

  for (int i = 1; i <= N; i++)
    if (root[i] > 0 && i == find(i))
      ans++;

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}