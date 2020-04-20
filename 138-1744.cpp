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

ll ans;
int N;
int A[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  int neg_cnt = 0, pos_cnt = 0, zero_cnt = 0, one_cnt = 0;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0)
      neg_cnt++;
    else if (A[i] > 1)
      pos_cnt++;
    else if (A[i] == 1)
      one_cnt++;
    else
      zero_cnt++;
  }

  sort(A, A + N);

  for (int i = 0; i < neg_cnt - 1; i += 2)
    ans += A[i] * A[i + 1];

  if (neg_cnt % 2)
    if (zero_cnt == 0)
      ans += A[neg_cnt - 1];

  for (int i = N - 1; i > N - pos_cnt; i -= 2)
    ans += A[i] * A[i - 1];

  if (pos_cnt % 2)
    ans += A[N - pos_cnt];

  cout << ans + one_cnt;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}