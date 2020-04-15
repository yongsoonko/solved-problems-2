#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  char i;
  char j;
};

Pos v[26];

void dfs(char curr, int num) {
  Pos p = v[curr - 'A'];

  if (num == 1)
    cout << curr;

  if (p.i != '.')
    dfs(p.i, num);

  if (num == 2)
    cout << curr;

  if (p.j != '.')
    dfs(p.j, num);

  if (num == 3)
    cout << curr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    v[a - 'A'].i = b;
    v[a - 'A'].j = c;
  }

  for (int i = 1; i <= 3; i++) {
    dfs('A', i);
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}