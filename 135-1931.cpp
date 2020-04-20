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
    if (j == p.j)
      return i < p.i;
    return j < p.j;
  }
};

int N, ans;
Pos A[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    A[i] = {a, b};
  }

  sort(A, A + N);

  int end = 0;
  for (int i = 0; i < N; i++)
    if (end <= A[i].i) {
      end = A[i].j;
      ans++;
    }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}