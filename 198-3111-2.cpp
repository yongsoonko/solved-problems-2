#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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

string A, T;
struct stack {
  char data[300000];
  int idx;
  stack() : idx(-1) {}
} lt, rt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> A >> T;

  int lo = 0, hi = T.size() - 1;
  while (lo <= hi) {
    while (lo <= hi) {
      lt.data[++lt.idx] = T[lo++];
      if (lt.idx + 1 >= A.size()) {
        int i, p = lt.idx - A.size() + 1;
        for (i = 0; i < A.size(); i++)
          if (lt.data[p + i] != A[i])
            break;
        if (i == A.size()) {
          lt.idx = max(-1, lt.idx - (int)A.size());
          break;
        }
      }
    }

    while (lo <= hi) {
      rt.data[++rt.idx] = T[hi--];
      if (rt.idx + 1 >= A.size()) {
        int i;
        for (i = 0; i < A.size(); i++)
          if (rt.data[rt.idx - i] != A[i])
            break;
        if (i == A.size()) {
          rt.idx = max(-1, rt.idx - (int)A.size());
          break;
        }
      }
    }
  }

  string ans;
  for (int i = 0; i <= lt.idx; i++)
    ans.push_back(lt.data[i]);
  for (int i = rt.idx; i >= 0; i--)
    ans.push_back(rt.data[i]);

  size_t p = 0;
  while ((p = ans.find(A, p)) != string::npos) {
    ans.erase(p, A.size());
    p = max((size_t)0, p - A.size());
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}