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

const int ALPHABET_SIZE = 26;
struct Trie {
  Trie *chk[ALPHABET_SIZE];
  bool isEnd;

  Trie() : isEnd(0) {
    fill(chk, chk + ALPHABET_SIZE, nullptr);
  }

  ~Trie() {
    for (Trie *t : chk)
      if (t)
        delete t;
  }

  void insert(const char *key) {
    if (*key == '\0') {
      isEnd = 1;
    } else {
      int curr = *key - 'a';
      if (!chk[curr])
        chk[curr] = new Trie;
      chk[curr]->insert(key + 1);
    }
  }

  bool find(const char *key) {
    if (*key == '\0') {
      return isEnd;
    } else {
      int curr = *key - 'a';
      if (!chk[curr])
        return 0;
      return chk[curr]->find(key + 1);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string keys[] = {"the", "a", "there",
                   "answer", "any", "by",
                   "bye", "their"};

  Trie *T = new Trie;
  for (string str : keys)
    T->insert(str.c_str());

  string list[] = {"the", "these", "their",
                   "thaw", "by"};
  for (string str : list)
    T->find(str.c_str()) ? cout << "YES\n" : cout << "NO\n";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}