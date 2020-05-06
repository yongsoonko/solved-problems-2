#include <algorithm>
#include <iostream>
#include <map>
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

int N, K;
string num, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> K >> num;

  for (int i = 0; i < N; i++) {
    // 스택 디깅
    while (ans.size() &&
           // 스택 개수 + 남은 검사 숫자 > 뽑을 수의 개수
           ans.size() + N - i > N - K &&
           ans.back() < num[i])
      ans.pop_back();
    ans.push_back(num[i]);
  }

  // 7654321 같은 케이스때문에 for문을 사용함.
  for (int i = 0; i < N - K; i++)
    cout << ans[i];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}