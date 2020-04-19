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
  int x;
  int y;
  bool operator<(const Pos &p) const {
    if (x == p.x)
      return y < p.y;
    return x < p.x;
  }
};

bool comp(const Pos &a, const Pos &b) {
  return a.y < b.y;
}

int N;
Pos P[100001];
Pos lt_half[50001], rt_half[50001];

int distance(Pos &a, Pos &b) {
  return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

// Closest Pair
int dfs(int lt, int rt) {
  int mn = 1e9;

  // 3개 이상 일 때 모두 검사하고 분할 종료
  if (rt - lt <= 2) {
    for (int i = lt; i < rt; i++)
      for (int j = i + 1; j <= rt; j++)
        mn = min(mn, distance(P[i], P[j]));
    return mn;
  }

  int mid = (lt + rt) / 2;
  mn = min(mn, dfs(lt, mid));
  mn = min(mn, dfs(mid + 1, rt));
  // 실수 주의 : mn은 제곱길이고 thresold는 실제길이임
  int threshold = sqrt(mn);

  Pos *lt_ptr = copy(lower_bound(P + lt, P + rt + 1, Pos{P[mid].x - threshold, -10001}), P + mid + 1, lt_half),
      *rt_ptr = copy(P + mid + 1, upper_bound(P + lt, P + rt + 1, Pos{P[mid + 1].x + threshold, 10001}), rt_half);

  sort(lt_half, lt_ptr, comp);
  sort(rt_half, rt_ptr, comp);

  int rt_idx = 0,
      lt_cnt = lt_ptr - lt_half,
      rt_cnt = rt_ptr - rt_half;
  for (int i = 0; i < lt_cnt; i++) {
    bool once = 1;
    for (int j = rt_idx; j < rt_cnt; j++) {
      int h = rt_half[j].y - lt_half[i].y;
      if (abs(h) <= threshold) {
        mn = min(mn, distance(lt_half[i], rt_half[j]));
        if (once && h <= 0)
          rt_idx = j;
      } else if (h > threshold)
        break;
    }
  }
  return mn;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    P[i] = {x, y};
  }

  sort(P, P + N);

  cout << dfs(0, N - 1);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}