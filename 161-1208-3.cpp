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
int cntA[4000001], cntB[4000001];

void dfs(int curr, int sum, int *arr, int *cnt) {
  int end = min(N, 20);
  for (int i = curr; i < end; i++) {
    dfs(i + 1, sum + arr[i], arr, cnt);
  }
  // 후위 순회하므로 부모에서 가장 늦게 push함.
  // 최상단 부모는 아무것도 선택하지 않는(cnt=0) 경우임.
  cnt[sum + 2000000]++;
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
  cntA[2000000]--;

  if (N > 20) {
    N -= 20;
    dfs(0, 0, B, cntB);
    cntB[2000000]--;

    // 두 배열이 각각 1개 이상 선택한 조합에서의 합
    for (int i = -2000000; i <= 2000000; i++)
      if (S - i >= -2000000 && S - i <= 2000000)
        ans += (ll)cntA[i + 2000000] * cntB[S - i + 2000000];
    // 하나의 배열에서만 선택(다른 배열은 선택안함)한 조합에서의 합
    ans += (ll)cntA[S + 2000000] + cntB[S + 2000000];
  } else
    ans += cntA[S + 2000000];

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}