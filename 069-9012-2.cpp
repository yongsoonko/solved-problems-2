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

char v[51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    int idx = -1;
    for (char ch : str) {
      if (ch == '(')
        v[++idx] = ch;
      else {
        if (idx >= 0 && v[idx] == '(')
          idx--;
        else
          v[++idx] = ch;
      }
    }
    if (idx == -1)
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}