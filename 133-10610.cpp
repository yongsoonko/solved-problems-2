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

bool comp(const char &a, const char &b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str;
  cin >> str;

  sort(str.begin(), str.end(), comp);

  int sum = 0;
  for (char ch : str)
    sum += ch - '0';

  if (sum % 3 || str.back() != '0') {
    cout << -1;
    return 0;
  }

  cout << str;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}