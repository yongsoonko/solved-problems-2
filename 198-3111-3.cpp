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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> A >> T;

  int lo = 0, hi = T.size() - 1;
  while (lo <= hi) {
    if ((lo = T.find(A, lo)) != string::npos) {
      T.erase(lo, A.size());
      lo = max(0, lo - (int)A.size());
      hi = max(0, hi - (int)A.size());
    } else
      break;
    if (lo <= hi && (hi = T.rfind(A, hi)) != string::npos) {
      T.erase(hi, A.size());
      hi = min((int)T.size() - 1, hi + (int)A.size());
    } else
      break;
  }

  int p = 0;
  while ((p = T.find(A, p)) != string::npos) {
    T.erase(p, A.size());
    p = max(0, p - (int)A.size());
  }

  cout << T;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}