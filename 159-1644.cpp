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
int A[300001];
bool prime[4000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 2; i * i <= N; i++)
    if (prime[i] == 0)
      for (int j = i + i; j <= N; j += i)
        prime[j] = 1;

  int cnt = 0;
  for (int i = 2; i <= N; i++)
    if (prime[i] == 0)
      A[cnt++] = i;

  int sum = 0, p = 0, q = 0;
  while (1) {
    if (sum < N) {
      if (q == cnt || A[q] > N)
        break;
      sum += A[q];
      q++;
    } else {
      if (sum == N)
        ans++;
      sum -= A[p];
      p++;
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}