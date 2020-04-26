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

int L, C;
char A[15], B[15];

void dfs(int curr, int cnt) {
  if (curr == C)
    if (cnt < L)
      return;

  if (cnt == L) {
    int mcnt = 0, jcnt = 0;
    for (int i = 0; i < L; i++) {
      if (B[i] == 'a' || B[i] == 'e' ||
          B[i] == 'i' || B[i] == 'o' || B[i] == 'u')
        mcnt++;
      else
        jcnt++;
    }
    if (mcnt >= 1 && jcnt >= 2) {
      for (int i = 0; i < L; i++)
        cout << B[i];
      cout << '\n';
    }
  } else {
    for (int i = curr; i < C; i++) {
      B[cnt] = A[i];
      dfs(i + 1, cnt + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> L >> C;

  for (int i = 0; i < C; i++)
    cin >> A[i];

  sort(A, A + C);

  dfs(0, 0);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}