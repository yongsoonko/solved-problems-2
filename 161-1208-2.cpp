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
  for (int i = curr; i < end; i++) {
    dfs(i + 1, sum + arr[i], arr, cnt);
  }
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
  // 아무것도 선택되지 않는 경우(부분수열의 크기가 0)는
  // cnt에 가장 마지막에 push됨. 이를 pop_back() 한다.
  // 두 배열이 각각 1개 이상 선택한 조합을 가져오기 위함
  cntA.pop_back();
  sort(cntA.begin(), cntA.end());

  if (N > 20) {
    N -= 20;
    dfs(0, 0, B, cntB);
    cntB.pop_back();
    sort(cntB.begin(), cntB.end());

    // 두 배열이 각각 1개 이상 선택한 조합에서의 합
    for (int i : cntA) {
      auto r = equal_range(cntB.begin(), cntB.end(), S - i);
      ans += r.second - r.first;
    }
    // 하나의 배열에서만 선택(다른 배열은 선택안함)한 조합에서의 합
    auto rA = equal_range(cntA.begin(), cntA.end(), S),
         rB = equal_range(cntB.begin(), cntB.end(), S);
    ans += rA.second - rA.first + rB.second - rB.first;
  } else {
    auto r = equal_range(cntA.begin(), cntA.end(), S);
    ans = r.second - r.first;
  }
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}