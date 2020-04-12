#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

class queue {
  int data[10001];
  int head, tail;

public:
  queue() : head(0), tail(0) {}
  void push(int x) {
    data[tail++] = x;
  }
  void pop() {
    if (tail - head == 0)
      cout << -1;
    else
      cout << data[head++];
    cout << '\n';
  }
  void size() {
    cout << tail - head << '\n';
  }
  void empty() {
    if (tail - head == 0)
      cout << 1;
    else
      cout << 0;
    cout << '\n';
  }
  void front() {
    if (tail - head == 0)
      cout << -1;
    else
      cout << data[head];
    cout << '\n';
  }
  void back() {
    if (tail - head == 0)
      cout << -1;
    else
      cout << data[tail - 1];
    cout << '\n';
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;

  queue q;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    if (str == "push") {
      int a;
      cin >> a;
      q.push(a);
    } else if (str == "pop")
      q.pop();
    else if (str == "size")
      q.size();
    else if (str == "empty")
      q.empty();
    else if (str == "front")
      q.front();
    else if (str == "back")
      q.back();
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}