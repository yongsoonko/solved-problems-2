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

vector<int> ans;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++)
    v.push_back(i);

  int pos = -1;
  while (ans.size() < N) {
    pos += K;
    if (pos >= v.size())
      pos %= v.size();
    ans.push_back(v[pos]);
    v.erase(v.begin() + pos);
    pos--;
  }

  cout << '<';
  for (int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] << ", ";
  cout << ans.back() << '>';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}