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

  vector<int> ans;
  int A, B, m, sum = 0;
  cin >> A >> B >> m;

  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    sum = sum * A + a;
  }

  do {
    ans.push_back(sum % B);
    sum /= B;
  } while (sum);

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}