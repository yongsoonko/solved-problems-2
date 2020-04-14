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

int A, P, ans;
int chk[300001];

void dfs(int curr) {
  int next = 0, num = curr;
  while (num) {
    int add = num % 10, mul = 1;
    for (int i = 0; i < P; i++)
      mul *= add;
    next += mul;
    num /= 10;
  }

  if (!chk[next]) {
    chk[next] = chk[curr] + 1;
    dfs(next);
  } else
    ans = chk[next] - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> A >> P;

  chk[A] = 1;
  dfs(A);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}