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

  int tc;
  cin >> tc;
  while (tc--) {
    string a, b;
    cin >> a >> b;
    cout << "Distances:";
    for (int i = 0; i < a.size(); i++) {
      if (a[i] > b[i])
        cout << ' ' << (b[i] + 26) - a[i];
      else
        cout << ' ' << b[i] - a[i];
    }
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}