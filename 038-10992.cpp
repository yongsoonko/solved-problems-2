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

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--)
      cout << ' ';
    cout << '*';
    if (i == 0) {
      cout << '\n';
      continue;
    }
    for (int j = 0; j < i * 2 - 1; j++)
      if (i == N - 1)
        cout << '*';
      else
        cout << ' ';
    cout << "*\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}