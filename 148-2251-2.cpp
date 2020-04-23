#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int A[3];
set<int> chk, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 0; i < 3; i++)
    cin >> A[i];

  chk.insert(A[2]);
  ans.insert(A[2]);

  queue<int> Q;
  Q.push(A[2]);

  while (Q.size()) {
    int curr = Q.front();
    Q.pop();

    int w;
    int B[3], tmp[3];
    for (int i = 2; i >= 0; i--) {
      B[i] = curr % 201;
      curr /= 201;
    }

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i != j) {
          w = min(B[i], A[j] - B[j]);
          tmp[i] = B[i] - w;
          tmp[j] = B[j] + w;
          tmp[3 - i - j] = B[3 - i - j];
          int next = 0;
          for (int i = 0; i < 3; i++)
            next = next * 201 + tmp[i];
          if (chk.find(next) == chk.end()) {
            chk.insert(next);
            Q.push(next);
          }
          if (!tmp[0])
            ans.insert(tmp[2]);
        }
  }

  for (int i : ans)
    cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}