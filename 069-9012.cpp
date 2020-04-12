#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    stack<char> s;
    string str;
    cin >> str;
    for (char ch : str) {
      if (ch == ')') {
        if (s.size() && s.top() == '(')
          s.pop();
        else {
          s.push(ch);
          break;
        }
      } else
        s.push(ch);
    }
    if (s.size())
      cout << "NO";
    else
      cout << "YES";
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}