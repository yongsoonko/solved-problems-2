#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int cnt;
  int flag;
};

int N, M, ans;
int chk[10];

Pos chkBtn(int num) {
  Pos ret = {0, 1};
  do {
    ret.cnt++;
    int digit = num % 10;
    num /= 10;
    if (!chk[digit]) {
      ret.flag = 0;
      break;
    }
  } while (num);

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  fill(chk, chk + 10, 1);
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    chk[a] = 0;
  }

  int thres = abs(N - 100);
  ans = thres;

  for (int d = 0; d <= thres; d++) {
    int num = max(N - d, 0), num2 = N + d;
    Pos ret = chkBtn(num);
    if (ret.flag)
      ans = min(ans, ret.cnt + d);

    ret = chkBtn(num2);
    if (ret.flag)
      ans = min(ans, ret.cnt + d);
  }
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}