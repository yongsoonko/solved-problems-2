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

int D1, D2, ans;
bool chk[2001][2001];
short cache[2001][2001];

// gcd도 재귀이므로 메모이제이션을 쓸 수 있다.
int gcd(int a, int b) {
  if (cache[a][b])
    return cache[a][b];
  return cache[a][b] = b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> D1 >> D2;

  for (int i = D1; i <= D2; i++)
    for (int j = 1; j <= i; j++) {
      int g = gcd(i, j);
      if (!chk[i / g][j / g]) {
        chk[i / g][j / g] = 1;
        ans++;
      }
    }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}