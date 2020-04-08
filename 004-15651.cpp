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

int N, M;
vector<int> ans;

void dfs(int curr) {
  if (curr == M) {
    for (int i : ans)
      cout << i << ' ';
    cout << '\n';
  } else {
    for (int i = 1; i <= N; i++) {
      ans.push_back(i);
      dfs(curr + 1);
      ans.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> N >> M;
    dfs(0);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}