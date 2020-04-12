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

class stack {
  int data[10001];
  int idx;

public:
  stack() : idx(-1) {}
  void push(int x) {
    data[++idx] = x;
  }
  void pop() {
    if (idx + 1 == 0)
      cout << -1;
    else
      cout << data[idx--];
    cout << '\n';
  }
  void size() {
    cout << idx + 1 << '\n';
  }
  void empty() {
    if (idx + 1 == 0)
      cout << 1;
    else
      cout << 0;
    cout << '\n';
  }
  void top() {
    if (idx + 1 == 0)
      cout << -1;
    else
      cout << data[idx];
    cout << '\n';
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  stack s;
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    if (str == "push") {
      int a;
      cin >> a;
      s.push(a);
    } else if (str == "pop")
      s.pop();
    else if (str == "size")
      s.size();
    else if (str == "empty")
      s.empty();
    else if (str == "top")
      s.top();
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}