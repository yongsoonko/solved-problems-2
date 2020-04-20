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

int N, K, ans;
int A[11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> K;

  for (int i = 1; i <= N; i++)
    cin >> A[i];

  for (int i = N; i > 0; i--) {
    ans += K / A[i];
    K %= A[i];
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}