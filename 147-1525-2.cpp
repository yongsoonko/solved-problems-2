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
  string i;
  int j;
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str, str2 = "123456780";
  int zero;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      char a;
      cin >> a;
      if (a == '0')
        zero = i * 3 + j;
      str += a;
    }

  set<string> chk;
  chk.insert(str);

  queue<Pos> Q;
  Q.push({str, zero});

  while (Q.size()) {
    if (chk.find(str2) != chk.end())
      break;
    ans++;
    int sz = Q.size();
    while (sz--) {
      Pos curr = Q.front();
      Q.pop();

      string str = curr.i;
      int ci = curr.j / 3, cj = curr.j % 3;
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
          int cc = curr.j, nn = ni * 3 + nj;
          swap(str[cc], str[nn]);
          if (chk.find(str) == chk.end()) {
            chk.insert(str);
            Q.push({str, nn});
          }
          swap(str[cc], str[nn]);
        }
      }
    }
  }

  if (chk.find(str2) != chk.end())
    cout << ans;
  else
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}