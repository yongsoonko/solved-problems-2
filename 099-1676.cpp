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

  int N, cnt2 = 0, cnt5 = 0;
  cin >> N;

  for (int i = 2; i <= N; i++) {
    int num = i;
    while (num % 2 == 0) {
      cnt2++;
      num /= 2;
    }
    while (num % 5 == 0) {
      cnt5++;
      num /= 5;
    }
  }

  cout << min(cnt2, cnt5);

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}