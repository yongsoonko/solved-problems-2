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

int N, ans;
int A[500001], B[500001], cnt[500001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  copy(A, A + N, B);
  sort(B, B + N);

  for (int i = 0; i < N; i++) {
    int lt = 0, rt = N-1, idx = 1e9;
    while (lt <= rt) {
      int mid = (lt + rt) / 2;
      if (A[i] <= B[mid]) {
        rt = mid - 1;
        idx = min(idx, mid);
      } else if (A[i] > B[mid])
        lt = mid + 1;
    }
    ans = max(ans, i - idx - cnt[idx]++);
  }

  cout << ans + 1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}