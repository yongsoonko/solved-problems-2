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

int prime[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int M, N;
  cin >> M >> N;

  prime[1] = 1;
  for (int i = 2; i <= N; i++)
    if (prime[i] == 0)
      for (int j = i + i; j <= N; j += i)
        prime[j] = 1;

  for (int i = M; i <= N; i++)
    if (prime[i] == 0)
      cout << i << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}