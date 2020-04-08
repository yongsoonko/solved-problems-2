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

  string date[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

  int a, b, c = 0;
  cin >> a >> b;

  for (int i = 1; i < a; i++)
    switch (i) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      c = (c + 31) % 7;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      c = (c + 30) % 7;
      break;
    case 2:
      c = (c + 28) % 7;
    }

  c = (c + b) % 7;
  cout << date[c];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}