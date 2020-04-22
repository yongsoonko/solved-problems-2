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

#define N 362880
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int seq[N], chk[N], ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int num[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int idx = 0;
  do {
    int sum = 0;
    for (int i = 0; i < 9; i++)
      sum = sum * 10 + num[i];
    seq[idx++] = sum;
  } while (next_permutation(num, num + 9));

  int sum = 0, Z;
  int E = lower_bound(seq, seq + N, 123456780) - seq;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int a;
      cin >> a;
      if (a == 0)
        Z = i * 3 + j;
      sum = sum * 10 + a;
    }
  int S = lower_bound(seq, seq + N, sum) - seq;
  chk[S] = 1;

  queue<Pos> Q;
  Q.push({sum, Z});

  while (Q.size()) {
    if (chk[E])
      break;
    ans++;
    int sz = Q.size();
    while (sz--) {
      Pos curr = Q.front();
      Q.pop();

      int ci = curr.j / 3, cj = curr.j % 3;
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
          int cNum = curr.i, cPos = curr.j;
          int d1 = 100000000, d2 = 100000000;
          for (int i = 0; i < cPos; i++)
            d1 /= 10;

          int nPos = ni * 3 + nj;
          for (int i = 0; i < nPos; i++)
            d2 /= 10;
          int nNum = ((cNum / d2) % 10) * d2;
          cNum -= nNum;
          nNum = cNum + nNum / d2 * d1;
          int next = lower_bound(seq, seq + N, nNum) - seq;

          if (!chk[next]) {
            chk[next] = 1;
            Q.push({nNum, nPos});
          }
        }
      }
    }
  }

  if (chk[E])
    cout << ans;
  else
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}