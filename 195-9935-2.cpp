#include <algorithm>
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

string str, bomb;
struct stack {
  char data[1000001];
  int idx;
  stack() : idx(-1) {}
  void push(char x) {
    data[++idx] = x;
  }
  void pop() {
    idx--;
  }
  char top() {
    return data[idx];
  }
} ans, S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> str >> bomb;

  for (char ch : str) {
    ans.push(ch);
    if (S.idx >= 0 && ch == bomb[S.top() + 1])
      S.push(S.top() + 1);
    else if (ch == bomb.front())
      S.push(0);
    else
      S.push(-1);

    if (S.top() == bomb.size() - 1) {
      S.idx -= bomb.size();
      ans.idx -= bomb.size();
    }
  }

  if (ans.idx >= 0) {
    ans.push('\0');
    cout << ans.data;
  } else
    cout << "FRULA";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}