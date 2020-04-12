#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i; // 국어
  int j; // 영어
  int k; // 수학
  string name;
  bool operator<(const Pos &p) const {
    if (i == p.i && j == p.j && k == p.k)
      return name < p.name;
    if (i == p.i && j == p.j)
      return k > p.k;
    if (i == p.i)
      return j < p.j;
    return i > p.i;
  }
};

Pos p[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> p[i].name >> p[i].i >> p[i].j >> p[i].k;

  sort(p, p + N);

  for (int i = 0; i < N; i++)
    cout << p[i].name << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}