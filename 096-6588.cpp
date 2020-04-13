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

bool prime[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  prime[1] = 1;
  for (int i = 2; i * i <= 1000000; i++)
    if (prime[i] == 0)
      for (int j = i + i; j <= 1000000; j += i)
        prime[j] = 1;

  int N;
  while (1) {
    cin >> N;
    if (N == 0)
      break;

    for (int i = 3; i < N; i++)
      if (prime[i] == 0 && prime[N - i] == 0) {
        cout << N << " = " << i << " + " << N - i << '\n';
        break;
      }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}