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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str, ans;
  cin >> str;

  int cnt = 0, sum = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    cnt++;
    sum += str[i] - '0' << (cnt - 1);
    if (cnt % 3 == 0) {
      ans.push_back('0' + sum);
      sum = cnt = 0;
    }
  }
  if (cnt)
    ans.push_back('0' + sum);

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}