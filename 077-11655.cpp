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

  string str;
  getline(cin, str);

  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = 'a' + (str[i] - 'a' + 13) % 26;
    else if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = 'A' + (str[i] - 'A' + 13) % 26;
  }

  cout << str;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}