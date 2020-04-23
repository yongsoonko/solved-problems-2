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
  int k;
};

int chk[201][201][201];
int A, B, C;
set<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> A >> B >> C;

  chk[0][0][C] = 1;
  queue<Pos> Q;
  Q.push({0, 0, C});
  ans.insert(C);

  while (Q.size()) {
    Pos curr = Q.front();
    Q.pop();

    int w;
    if (curr.i) {
      w = min(curr.i, B - curr.j);
      if (w > 0 && !chk[curr.i - w][curr.j + w][curr.k]) {
        chk[curr.i - w][curr.j + w][curr.k] = 1;
        Q.push({curr.i - w, curr.j + w, curr.k});
        if (!(curr.i - w))
          ans.insert(curr.k);
      }

      w = min(curr.i, C - curr.k);
      if (w > 0 && !chk[curr.i - w][curr.j][curr.k + w]) {
        chk[curr.i - w][curr.j][curr.k + w] = 1;
        Q.push({curr.i - w, curr.j, curr.k + w});
        if (!(curr.i - w))
          ans.insert(curr.k + w);
      }
    }
    if (curr.j) {
      w = min(A - curr.i, curr.j);
      if (w > 0 && !chk[curr.i + w][curr.j - w][curr.k]) {
        chk[curr.i + w][curr.j - w][curr.k] = 1;
        Q.push({curr.i + w, curr.j - w, curr.k});
      }

      w = min(curr.j, C - curr.k);
      if (w > 0 && !chk[curr.i][curr.j - w][curr.k + w]) {
        chk[curr.i][curr.j - w][curr.k + w] = 1;
        Q.push({curr.i, curr.j - w, curr.k + w});
        if (!curr.i)
          ans.insert(curr.k + w);
      }
    }
    if (curr.k) {
      w = min(A - curr.i, curr.k);
      if (w > 0 && !chk[curr.i + w][curr.j][curr.k - w]) {
        chk[curr.i + w][curr.j][curr.k - w] = 1;
        Q.push({curr.i + w, curr.j, curr.k - w});
      }

      w = min(B - curr.j, curr.k);
      if (w > 0 && !chk[curr.i][curr.j + w][curr.k - w]) {
        chk[curr.i][curr.j + w][curr.k - w] = 1;
        Q.push({curr.i, curr.j + w, curr.k - w});
        if (!curr.i)
          ans.insert(curr.k - w);
      }
    }
  }

  // sort(ans.begin(), ans.end());

  for (int i : ans)
    cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}