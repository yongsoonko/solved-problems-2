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

int dp[3][5001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str;
  cin >> str;

  // 0으로 시작하는 경우 암호가 잘못되어 해석할 수 없다고 함
  if (str[0] == '0') {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < str.size(); i++) {
    if (i == 0)
      dp[1][0] = 1;
    else {
      int num = (str[i - 1] - '0') * 10 + str[i] - '0';
      if (str[i] == '0') {
        dp[1][i] = 0;
        if (num >= 1 && num <= 26) {
          dp[2][i] = dp[1][i - 1];
        } else {
          // 0X는 X와 같은 의미로 해석될 수 없음
          cout << 0;
          return 0;
        }
      } else {
        dp[1][i] = (dp[1][i - 1] + dp[2][i - 1]) % 1000000;
        if (num >= 1 && num <= 26)
          dp[2][i] = dp[1][i - 1];
      }
    }
  }

  cout << (dp[1][str.size() - 1] + dp[2][str.size() - 1]) % 1000000;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}