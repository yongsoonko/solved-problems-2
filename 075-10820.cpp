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

int cnt[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str;
  while (getline(cin, str)) {
    fill(cnt, cnt + 4, 0);
    for (char ch : str) {
      if (ch >= 'a' && ch <= 'z')
        cnt[0]++;
      else if (ch >= 'A' && ch <= 'Z')
        cnt[1]++;
      else if (ch >= '0' && ch <= '9')
        cnt[2]++;
      else if (ch == ' ')
        cnt[3]++;
    }
    for (int i = 0; i < 4; i++)
      cout << cnt[i] << ' ';
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}