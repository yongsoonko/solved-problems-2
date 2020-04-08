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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, sign = 1;
  cin >> N;

  for (int i = 0; i >= 0; i += sign) {
    for (int j = 0; j <= i; j++)
      cout << '*';
    for (int j = N * 2 - 2; j > i * 2; j--)
      cout << ' ';
    for (int j = 0; j <= i; j++)
      cout << '*';
    cout << '\n';
    if (i == N - 1)
      sign = -1;
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}