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

  for (char ch : num) {
    while (K && ans.size() && ans.back() < ch) {
      ans.pop_back();
      K--;
    }
    ans.push_back(ch);
  }

  for (int i = 0; i < ans.size() - K; i++)
    cout << ans[i];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}