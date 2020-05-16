#include <algorithm>
#include <iostream>
#include <map>
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

string A, B, L2, R2;
deque<char> T, L, R;

bool go(deque<char> &D) {
  while (D.size()) {
    char ch = D.front();
    L.push_back(ch);
    L2.push_back(ch);
    D.pop_front();
    if (A[L2.size() - 1] == ch) {

      if (L2.size() == A.size()) {
        for (int i = 0; i < A.size(); i++)
          L.pop_back();
        for (int i = 0; L.size() && i < A.size(); i++) {
          D.push_front(L.back());
          L.pop_back();
        }
        L2 = "";
        return 1;
      }
    } else {
      for (int i = 1; i < L2.size(); i++) {
        D.push_front(L.back());
        L.pop_back();
      }
      L2 = "";
    }
  } // while
  return 0;
}

bool go2(deque<char> &D) {
  while (D.size()) {
    char ch = D.back();
    R.push_front(ch);
    R2.push_back(ch);
    D.pop_back();
    if (B[R2.size() - 1] == ch) {

      if (R2.size() == B.size()) {
        for (int i = 0; i < B.size(); i++)
          R.pop_front();
        for (int i = 0; R.size() && i < B.size(); i++) {
          D.push_back(R.front());
          R.pop_front();
        }
        R2 = "";
        return 1;
      }
    } else {
      for (int i = 1; i < R2.size(); i++) {
        D.push_back(R.front());
        R.pop_front();
      }
      R2 = "";
    }
  } // while
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string str;
  cin >> A >> str;
  for (char ch : str)
    T.push_back(ch);
  B = A;
  reverse(B.begin(), B.end());

  while (1) {
    if (!go(T) && !go(R))
      break;
    if (!go2(T) && !go2(L))
      break;
  }

  string ans;
  for (char ch : L)
    ans += ch;
  for (char ch : R)
    ans += ch;

  int pos = 0;
  while ((pos = ans.find(A, pos)) != string::npos) {
    ans.erase(pos, A.size());
    pos = 0;
  }
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}