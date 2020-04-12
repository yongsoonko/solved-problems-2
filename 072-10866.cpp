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

class deque {
  int data[30001];
  int head, tail;

public:
  deque() : head(15000), tail(15000) {}
  void push_front(int x) {
    data[--head] = x;
  }
  void push_back(int x) {
    data[tail++] = x;
  }
  void pop_front() {
    if (tail - head == 0)
      cout << -1;
    else
      cout << data[head++];
    cout << '\n';
  }
  void pop_back() {
    if (tail - head == 0)
      cout << -1;
    else
      cout << data[--tail];
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

  deque dq;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    if (str == "push_front") {
      int a;
      cin >> a;
      dq.push_front(a);
    } else if (str == "push_back") {
      int a;
      cin >> a;
      dq.push_back(a);
    } else if (str == "pop_front")
      dq.pop_front();
    else if (str == "pop_back")
      dq.pop_back();
    else if (str == "size")
      dq.size();
    else if (str == "empty")
      dq.empty();
    else if (str == "front")
      dq.front();
    else if (str == "back")
      dq.back();
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}