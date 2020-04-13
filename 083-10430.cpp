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

  int A, B, C;
  cin >> A >> B >> C;

  cout << (A + B) % C << '\n'
       << ((A % C) + (B % C)) % C << '\n'
       << (A * B) % C << '\n'
       << ((A % C) * (B % C)) % C;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}