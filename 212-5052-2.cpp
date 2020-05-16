#include <algorithm>
#include <cassert>
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

int t, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> t;
  while (t--) {
    cin >> n;
    vector<string> S;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      S.push_back(str);
    }
    sort(S.begin(), S.end());

    int i, j;
    for (i = 0; i < n - 1; i++) {
      for (j = 0; S[i][j] == S[i + 1][j]; j++) {}
      if (S[i][j] == '\0')
        break;
    }
    if (i == n - 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}