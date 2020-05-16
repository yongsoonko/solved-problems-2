#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int h;
};

int N;
stack<Pos> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  S.push({0, int(2e9)});
  for (int i = 1; i <= N; i++) {
    Pos p = {i};
    cin >> p.h;
    while (S.size() && S.top().h < p.h)
      S.pop();
    cout << S.top().i << ' ';
    S.push(p);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}