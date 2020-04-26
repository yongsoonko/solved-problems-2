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
int A[4001], B[4001], C[4001], D[4001];
vector<int> cntAB, cntCD;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i] >> C[i] >> D[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cntAB.push_back(A[i] + B[j]);
      cntCD.push_back(C[i] + D[j]);
    }

  sort(cntAB.begin(), cntAB.end());
  sort(cntCD.begin(), cntCD.end());

  int sum, p = 0, q = cntCD.size() - 1, p2, q2;
  while (p < cntAB.size() && q >= 0) {
    sum = cntAB[p] + cntCD[q];
    if (sum < 0)
      p++;
    else if (sum > 0)
      q--;
    else {
      p2 = p, q2 = q;
      while (p < cntAB.size() && cntAB[p] == cntAB[p2])
        p++;
      while (q >= 0 && cntCD[q] == cntCD[q2])
        q--;
      ans += (ll)(p - p2) * (q2 - q);
    }
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}