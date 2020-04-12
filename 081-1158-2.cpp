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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, K;
  cin >> N >> K;

  queue<int> q;
  for (int i = 1; i <= N; i++)
    q.push(i);

  int cnt = 0;
  while (q.size()) {
    cnt++;
    if (cnt == K) {
      ans.push_back(q.front());
      cnt = 0;
    } else
      q.push(q.front());
    q.pop();
  }

  cout << '<';
  for (int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] << ", ";
  cout << ans.back() << '>';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}