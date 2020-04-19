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
  bool operator<(const Pos &p) const {
    if (i == p.i)
      return j < p.j;
    return i < p.i;
  }
};

Pos A[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, ans = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    A[i] = {a, b};
  }

  sort(A, A + N);

  int end = -2e9;
  for (int i = 0; i < N; i++) {
    if (end > A[i].i) {
      if (A[i].j > end) {
        ans += A[i].j - end;
        end = A[i].j;
      }
    } else {
      ans += A[i].j - A[i].i;
      end = A[i].j;
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}