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

  string A, B, C, D;
  cin >> A >> B >> C >> D;
  A += B;
  C += D;

  ll a = 0, b = 0;
  for (char ch : A)
    a = a * 10 + ch - '0';

  for (char ch : C)
    b = b * 10 + ch - '0';

  cout << a + b;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}