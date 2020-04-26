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

int K;
int A[14], B[15], C[15];

void dfs(int cnt, int curr) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++)
      cout << B[i] << ' ';
    cout << '\n';
  } else if (curr < K) {
    B[cnt] = A[curr];
    dfs(cnt + 1, curr + 1);
    dfs(cnt, curr + 1);
  }
}

void dfs(int cnt, int curr, int dummy) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++)
      cout << B[i] << ' ';
    cout << '\n';
  } else {
    for (int i = curr; i < K; i++) {
      B[cnt] = A[i];
      dfs(cnt + 1, i + 1, 0);
    }
  }
}

void combi() {
  fill(C, C + K, 0);
  for (int i = 0; i < 6; i++)
    C[i] = 1;

  do {
    for (int i = 0; i < K; i++)
      if (C[i])
        cout << A[i] << ' ';
    cout << '\n';
  } while (prev_permutation(C, C + K));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    cin >> K;
    if (K == 0)
      break;

    for (int i = 0; i < K; i++)
      cin >> A[i];

    dfs(0, 0);
    // dfs(0, 0, 0);
    // combi();

    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}