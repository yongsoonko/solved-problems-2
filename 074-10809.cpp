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

int idx[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str;
  cin >> str;

  fill(idx, idx + 26, -1);

  for (int i = 0; i < str.size(); i++)
    if (idx[str[i] - 'a'] == -1)
      idx[str[i] - 'a'] = i;

  for (int i = 0; i < 26; i++)
    cout << idx[i] << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}