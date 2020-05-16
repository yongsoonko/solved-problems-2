#include <algorithm>
#include <cassert>
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

const int NUMBER_SIZE = 10;
struct Trie {
  Trie *chk[NUMBER_SIZE];
  bool isEnd;
  bool hasNext;

  Trie() : isEnd(0), hasNext(0) {
    fill(chk, chk + NUMBER_SIZE, nullptr);
  }

  ~Trie() {
    for (Trie *t : chk)
      if (t)
        delete t;
  }

  bool insert(const char *key) {
    if (*key == '\0') {
      isEnd = 1;
      return !hasNext;
    } else {
      int curr = *key - '0';
      if (!chk[curr])
        chk[curr] = new Trie;
      hasNext = 1;
      return !isEnd && chk[curr]->insert(key + 1);
    }
  }
};

int t, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> t;
  while (t--) {
    cin >> n;
    Trie T;
    bool flag = 1;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      if (flag && T.insert(str.c_str()) == false)
        flag = 0;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}