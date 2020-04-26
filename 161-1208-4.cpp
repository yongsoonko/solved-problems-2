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
int N, S;
int A[21], B[21];
vector<int> cntA, cntB;

void dfs(int curr, int sum, int *arr, vector<int> &cnt) {
  int end = min(N, 20);
  for (int i = curr; i < end; i++)
    dfs(i + 1, sum + arr[i], arr, cnt);
  // 후위 순회하므로 부모에서 가장 늦게 push함.
  // 최상단 부모는 아무것도 선택하지 않는(cnt=0) 경우임.
  cnt.push_back(sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S;

  for (int i = 0; i < 20; i++)
    cin >> A[i];

  for (int i = 0; i < N - 20; i++)
    cin >> B[i];

  dfs(0, 0, A, cntA);
  sort(cntA.begin(), cntA.end());

  if (N > 20) {
    N -= 20;
    dfs(0, 0, B, cntB);
    sort(cntB.begin(), cntB.end());

    int sum, p = 0, q = cntB.size() - 1, p2, q2;
    while (p < cntA.size() && q >= 0) {
      sum = cntA[p] + cntB[q];
      if (sum > S)
        q--;
      else if (sum < S)
        p++;
      else {
        p2 = p, q2 = q;
        while (p < cntA.size() && cntA[p] == cntA[p2])
          p++;
        while (q >= 0 && cntB[q] == cntB[q2])
          q--;
        ans += (ll)(p - p2) * (q2 - q);
      }
    }

    while (p < cntA.size())
      if (cntA[p] > S)
        break;
      else {
        if (cntA[p] == S)
          ans++;
        p++;
      }

    while (q >= 0)
      if (cntB[q] < S)
        break;
      else {
        if (cntB[q] == S)
          ans++;
        q--;
      }
  } else {
    auto r = equal_range(cntA.begin(), cntA.end(), S);
    ans = r.second - r.first;
  }
  if (S == 0)
    ans--;
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}