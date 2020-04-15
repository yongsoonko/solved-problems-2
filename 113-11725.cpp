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

int N;
int chk[100001];
vector<int> E[100001];

void dfs(int curr) {
  for (int next : E[curr])
    if (!chk[next]) {
      chk[next] = curr;
      dfs(next);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  chk[1] = 1;
  dfs(1);
  for (int i = 2; i <= N; i++)
    cout << chk[i] << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}