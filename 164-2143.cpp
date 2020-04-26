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
int N, M, T;
int A[1001], B[1001];
vector<int> cntA, cntB;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> T >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  cin >> M;

  for (int i = 0; i < M; i++)
    cin >> B[i];

  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      cntA.push_back(sum);
    }
  }

  for (int i = 0; i < M; i++) {
    int sum = 0;
    for (int j = i; j < M; j++) {
      sum += B[j];
      cntB.push_back(sum);
    }
  }

  sort(cntA.begin(), cntA.end());
  sort(cntB.begin(), cntB.end());

  int sum, p = 0, q = cntB.size() - 1, p2, q2;
  while (p < cntA.size() && q >= 0) {
    sum = cntA[p] + cntB[q];
    if (sum < T)
      p++;
    else if (sum > T)
      q--;
    else {
      p2 = p, q2 = q;
      while (p < cntA.size() && cntA[p] == cntA[p2])
        p++;
      while (q >= 0 && cntB[q] == cntB[q2])
        q--;
      ans += (ll)(p - p2) * (q2 - q);
    }
  }
  
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}