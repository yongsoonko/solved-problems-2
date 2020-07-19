#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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

vector<int> solution(int n) {
  if (n == 1)
    return {0};
  else {
    vector<int> v = solution(n - 1);
    int sz = v.size();
    v.push_back(0);
    for (int i = sz - 1; i >= 0; i--)
      v.push_back(!v[i]);
    return v;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 1; i <= 3; i++) {
    vector<int> ret = solution(i);
    for (int j : ret)
      cout << j << ' ';
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}