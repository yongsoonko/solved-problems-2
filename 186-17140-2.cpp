#include <algorithm>
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
  bool operator<(const Pos &p) const {
    if (j == p.j)
      return i < p.i;
    return j < p.j;
  }
};

int r, c, k;
int A[101][101];
map<int, int> cnt;
vector<Pos> num;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> r >> c >> k;
  r--, c--;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> A[i][j];

  int rSz = 3, cSz = 3;
  for (int sec = 0; sec <= 100; sec++) {
    if (A[r][c] == k) {
      cout << sec;
      return 0;
    }
    if (rSz >= cSz) {
      int cMax = 0;
      for (int i = 0; i < rSz; i++) {
        for (int j = 0; j < cSz; j++) {
          if (A[i][j])
            cnt[A[i][j]]++;
        }
        for (auto a : cnt)
          num.push_back({a.first, a.second});
        sort(num.begin(), num.end());
        int j;
        for (j = 0; j < min(50, (int)num.size()); j++) {
          A[i][j * 2] = num[j].i;
          A[i][j * 2 + 1] = num[j].j;
        }
        cMax = max(cMax, j * 2);
        for (; j < 50; j++)
          A[i][j * 2] = A[i][j * 2 + 1] = 0;

        map<int, int>().swap(cnt);
        vector<Pos>().swap(num);
      }
      cSz = cMax;
    } else {
      int rMax = 0;
      for (int j = 0; j < cSz; j++) {
        for (int i = 0; i < rSz; i++) {
          if (A[i][j])
            cnt[A[i][j]]++;
        }
        for (auto a : cnt)
          num.push_back({a.first, a.second});
        sort(num.begin(), num.end());
        int i;
        for (i = 0; i < min(50, (int)num.size()); i++) {
          A[i * 2][j] = num[i].i;
          A[i * 2 + 1][j] = num[i].j;
        }
        rMax = max(rMax, i * 2);
        for (; i < 50; i++)
          A[i * 2][j] = A[i * 2 + 1][j] = 0;
        map<int, int>().swap(cnt);
        vector<Pos>().swap(num);
      }
      rSz = rMax;
    }
  }
  cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}