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

struct Node {
  char ch;
  Node *prev;
  Node *next;
};

class list {
  Node *head;
  Node *curr;

public:
  list(string str) {
    curr = new Node{str.front(), NULL, NULL};
    head = curr;
    for (int i = 1; i <= str.size(); i++) {
      curr->next = new Node{str[i], curr, NULL};
      curr = curr->next;
    }
  }
  void print() {
    Node *p = head;
    while (p) {
      if (p->next)
        cout << p->ch;
      p = p->next;
    }
    cout << '\n';
  }
  void L() {
    if (curr->prev)
      curr = curr->prev;
  }
  void D() {
    if (curr->next)
      curr = curr->next;
  }
  void B() {
    // 두 번째 위치일 때
    if (curr->prev) {
      Node *cut = curr->prev;
      // 세 번째 위치부터 일 때
      if (curr->prev->prev) {
        curr->prev->prev->next = curr;
        curr->prev = curr->prev->prev;
        delete cut;
      } else {
        head = curr;
        curr->prev = NULL;
        delete cut;
      }
    }
  }
  void P(char ch) {
    if (curr->prev) {
      curr->prev->next = new Node({ch, curr->prev, curr});
      curr->prev = curr->prev->next;
    } else {
      curr->prev = new Node({ch, NULL, curr});
      head = curr->prev;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    string str;
    int N;

    cin >> str >> N;
    list l(str);

    for (int i = 0; i < N; i++) {
      char ch;
      cin >> ch;
      if (ch == 'L')
        l.L();
      else if (ch == 'D')
        l.D();
      else if (ch == 'B')
        l.B();
      else if (ch == 'P') {
        cin >> ch;
        l.P(ch);
      }
    }
    l.print();
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}