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
int A[500001], B[500001];

void sort(int lt, int rt) {
  if (lt >= rt)
    return;

  int mid = (lt + rt) / 2;
  sort(lt, mid);
  sort(mid + 1, rt);

  int i = lt, j = mid + 1, k = lt;
  while (i <= mid && j <= rt) {
    if (A[i] <= A[j])
      B[k++] = A[i++];
    else {
      B[k++] = A[j++];
      ans += mid + 1 - i;
    }
  }

  while (i <= mid)
    B[k++] = A[i++];

  while (j <= rt)
    B[k++] = A[j++];

  for (int i = lt; i <= rt; i++)
    A[i] = B[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  sort(0, N - 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}