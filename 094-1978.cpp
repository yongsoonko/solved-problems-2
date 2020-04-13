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

int prime[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  prime[1] = 1;
  for (int i = 2; i * i <= 1000; i++)
    if (prime[i] == 0)
      for (int j = i + i; j <= 1000; j += i)
        prime[j] = 1;

  int N, ans = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (prime[a] == 0)
      ans++;
  }
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}