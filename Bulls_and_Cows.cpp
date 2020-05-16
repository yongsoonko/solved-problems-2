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

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  clock_t start = clock();

  srand((unsigned)time(NULL));

  int seq[9];
  vector<int> ans;
  for (int i = 0; i < 9; i++)
    seq[i] = i + 1;
  for (int i = 0; i < 3; i++) {
    swap(seq[9 - i - 1], seq[rand() % (9 - i)]);
    ans.push_back(seq[9 - i - 1]);
  }

  cout << "Ans : ";
  for (int i : ans)
    cout << i << ' ';
  cout << "\nType 3 Nums with each seperated with spaces.\n";

  while (1) {
    vector<int> v(3);
    for (int &i : v)
      cin >> i;

    int sCnt = 0, bCnt = 0;
    bool chk[3] = {0};
    for (int i = 0; i < 3; i++) {
      if (v[i] == ans[i])
        sCnt++;
      chk[i] = 1;
      for (int j = 0; j < 3; j++)
        if (!chk[j] && v[i] == ans[j])
          bCnt++;
      chk[i] = 0;
    }

    if (sCnt + bCnt > 0) {
      cout << sCnt << "S " << bCnt << "B\n\n";
      if (sCnt == 3)
        break;
    } else
      cout << "OUT\n\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}