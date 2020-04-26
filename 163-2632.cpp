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
int M, N, S;
int A[1001], B[1001];
vector<int> cntA, cntB;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> S >> M >> N;

  int sumA = 0, sumB = 0;
  for (int i = 0; i < M; i++) {
    cin >> A[i];
    sumA += A[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
    sumB += B[i];
  }

  cntA.push_back(sumA);
  cntB.push_back(sumB);

  for (int i = 0; i < M; i++) {
    int sum = 0;
    for (int j = 0; j <= M - 2; j++) {
      sum += A[(i + j) % M];
      cntA.push_back(sum);
    }
  }

  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j <= N - 2; j++) {
      sum += B[(i + j) % N];
      cntB.push_back(sum);
    }
  }

  sort(cntA.begin(), cntA.end());
  sort(cntB.begin(), cntB.end());

  int sum, p = 0, q = cntB.size() - 1, p2, q2;
  while (p < cntA.size() && q >= 0) {
    sum = cntA[p] + cntB[q];
    if (sum < S)
      p++;
    else if (sum > S)
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

  auto rA = equal_range(cntA.begin(), cntA.end(), S),
       rB = equal_range(cntB.begin(), cntB.end(), S);

  cout << ans + rA.second - rA.first + rB.second - rB.first;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}