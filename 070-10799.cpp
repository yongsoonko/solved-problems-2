#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

  string str;
  stack<char> s;
  cin >> str;

  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(')
      s.push(str[i]);
    else {
      s.pop();
      if (str[i - 1] == '(')
        ans += s.size();
      else
        ans++;
    }
  }
  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}