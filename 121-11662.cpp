#include <algorithm>
#include <cmath>
#include <iomanip>
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

long double distance(double fi_x, double fi_y, double se_x, double se_y) {
  return sqrtl(powl(se_x - fi_x, 2) + powl(se_y - fi_y, 2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  double ans = 1e9;
  int ax, ay, bx, by, cx, cy, dx, dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

  double lt_fi_x = ax,
         rt_fi_x = bx,
         lt_fi_y = ay,
         rt_fi_y = by,
         lt_se_x = cx,
         rt_se_x = dx,
         lt_se_y = cy,
         rt_se_y = dy;
  while (abs(rt_fi_x - lt_fi_x) >= 0.0000000001) {
    double mid_fi_x = (rt_fi_x - lt_fi_x) / 3,
           mid_fi_y = (rt_fi_y - lt_fi_y) / 3,
           mid_se_x = (rt_se_x - lt_se_x) / 3,
           mid_se_y = (rt_se_y - lt_se_y) / 3,
           dist1 = distance(lt_fi_x, lt_fi_y, lt_se_x, lt_se_y),
           dist2 = distance(lt_fi_x + mid_fi_x, lt_fi_y + mid_fi_y, lt_se_x + mid_se_x, lt_se_y + mid_se_y),
           dist3 = distance(rt_fi_x - mid_fi_x, rt_fi_y - mid_fi_y, rt_se_x - mid_se_x, rt_se_y - mid_se_y),
           dist4 = distance(rt_fi_x, rt_fi_y, rt_se_x, rt_se_y);

    if (dist3 - dist2 >= 0) {
      rt_fi_x -= mid_fi_x;
      rt_fi_y -= mid_fi_y;
      rt_se_x -= mid_se_x;
      rt_se_y -= mid_se_y;
      ans = min(ans, min(dist1, dist2));
    } else {
      lt_fi_x += mid_fi_x;
      lt_fi_y += mid_fi_y;
      lt_se_x += mid_se_x;
      lt_se_y += mid_se_y;
      ans = min(ans, min(dist3, dist4));
    }
  }
  cout << setprecision(12) << fixed << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}