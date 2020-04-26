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

int N, S, ans = 1e9;
int A[100001], B[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  B[0] = 0;
  for (int i = 0; i < N; i++)
    B[i + 1] = B[i] + A[i];

  int lt = 1, rt = N;
  while (lt <= rt) {
    int mid = (lt + rt) / 2, i;
    for (i = N - mid; i >= 0; i--)
      if (B[i + mid] - B[i] >= S)
        break;
    if (i < 0)
      lt = mid + 1;
    else {
      ans = min(ans, mid);
      rt = mid - 1;
    }
  }

  if (ans == 1e9)
    cout << 0;
  else
    cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}