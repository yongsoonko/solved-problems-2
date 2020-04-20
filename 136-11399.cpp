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
int P[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> P[i];

  sort(P, P + N);

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += P[i];
    ans += sum;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}