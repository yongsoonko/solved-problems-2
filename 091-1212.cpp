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

  if (str == "0") {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < str.size(); i++) {
    string str2;
    int a = str[i] - '0';
    while (a) {
      str2.push_back('0' + (a % 2));
      a /= 2;
    }
    if (i >= 1)
      for (int j = 0; j < 3 - str2.size(); j++)
        ans.push_back('0');
    for (int j = str2.size() - 1; j >= 0; j--)
      ans.push_back(str2[j]);
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}