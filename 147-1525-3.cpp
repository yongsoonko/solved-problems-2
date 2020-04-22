#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int sum = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int a;
      cin >> a;
      sum = sum * 10 + a;
    }

  set<int> chk;
  chk.insert(sum);

  queue<int> Q;
  Q.push(sum);

  int map[3][3];
  while (Q.size()) {
    if (chk.find(123456780) != chk.end())
      break;
    ans++;
    int sz = Q.size();
    while (sz--) {
      int curr = Q.front();
      Q.pop();

      int tmp = curr, ci, cj;
      for (int i = 2; i >= 0; i--)
        for (int j = 2; j >= 0; j--) {
          int digit = tmp % 10;
          if (digit == 0)
            ci = i, cj = j;
          map[i][j] = digit;
          tmp /= 10;
        }
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
          swap(map[ci][cj], map[ni][nj]);
          int next = 0;
          for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
              next = next * 10 + map[i][j];
          if (chk.find(next) == chk.end()) {
            chk.insert(next);
            Q.push(next);
          }
          swap(map[ci][cj], map[ni][nj]);
        }
      }
    }
  }

  if (chk.find(123456780) != chk.end())
    cout << ans;
  else
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}