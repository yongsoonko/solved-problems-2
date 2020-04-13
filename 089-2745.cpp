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

  string N;
  int B;
  cin >> N >> B;

  int sum = 0;
  for (char ch : N) {
    if (ch >= 'A' && ch <= 'Z')
      sum = sum * B + (ch - 'A') + 10;
    else
      sum = sum * B + ch - '0';
  }

  cout << sum;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}