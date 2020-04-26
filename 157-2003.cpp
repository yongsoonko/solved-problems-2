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

int N, M, ans;
int A[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  int sum = 0, p = 0, q = 0;
  while (1) {
    if (sum < M) {
      if (q == N)
        break;
      sum += A[q];
      q++;
    } else {
      if (sum == M)
        ans++;
      sum -= A[p];
      p++;
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}