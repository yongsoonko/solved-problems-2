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
  char j;
};

string d = "DSLR";
int T, A, B;
int chk[10000];
char chk2[10000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> T;

  while (T--) {
    cin >> A >> B;

    fill(chk, chk + 10000, -1);
    fill(chk2, chk2 + 10000, 0);

    chk[A] = -2;
    chk2[A] = '\0';
    queue<int> Q;
    Q.push(A);

    while (Q.size()) {
      int curr = Q.front();
      Q.pop();

      int d1 = curr / 1000,
          d4 = curr % 10,
          N[4] = {(curr * 2) % 10000,
                  curr == 0 ? 9999 : curr - 1,
                  (curr - d1 * 1000) * 10 + d1,
                  (curr - d4) / 10 + d4 * 1000};
      for (int i = 0; i < 4; i++) {
        int next = N[i];
        if (chk[next] == -1) {
          chk[next] = curr;
          chk2[next] = d[i];
          Q.push(next);
          if (next == B)
            goto out;
        }
      }
    }
  out:

    string ans;
    do {
      ans += chk2[B];
      B = chk[B];
    } while (B != A);

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}