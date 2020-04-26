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
int A[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  int sum = 0, p = 0, q = 0;
  while (1) {
    if (sum < S) {
      if (q == N)
        break;
      sum += A[q];
      q++;
    } else {
      ans = min(ans, q - p);
      sum -= A[p];
      p++;
    }
  }

  if (ans == 1e9)
    cout << 0;
  else
    cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}