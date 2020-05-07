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

string str, bomb, ans;
vector<int> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> str >> bomb;

  for (char ch : str) {
    ans.push_back(ch);
    if (S.size() && ch == bomb[S.back() + 1])
      S.push_back(S.back() + 1);
    else if (ch == bomb.front())
      S.push_back(0);
    else
      S.push_back(-1);

    if (S.back() == bomb.size() - 1)
      for (int i = 0; i < bomb.size(); i++) {
        S.pop_back();
        ans.pop_back();
      }
  }

  if (ans.size())
    cout << ans;
  else
    cout << "FRULA";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}