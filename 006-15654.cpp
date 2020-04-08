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
int chk[9];
vector<int> ans, v;

void dfs(int curr) {
  if (curr == M) {
    for (int i : ans)
      cout << i << ' ';
    cout << '\n';
  } else {
    for (int i = 0; i < v.size(); i++) {
      if (chk[i])
        continue;
      chk[i] = 1;
      ans.push_back(v[i]);
      dfs(curr + 1);
      chk[i] = 0;
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
    vector<int>().swap(v);
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    dfs(0);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}