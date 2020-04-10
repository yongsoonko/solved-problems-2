#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  string n;
  cin >> n;
  if (n[0] == '0') {
    // n = n.substr(1);
    cout << 0;
  } else {

    vector<int> v(n.size() + 1, 0);

    v[0] = 1;
    string tmp = n.substr(0, 1);
    int a = atoi(tmp.c_str());
    if (a >= 1 && a <= 9) {
      v[1] = 1;
    }

    for (int i = 1; i < n.size(); i++) {
      string tmp = n.substr(i, 1);
      string tmp2 = n.substr(i - 1, 2);
      int a = atoi(tmp.c_str());
      int b = atoi(tmp2.c_str());

      if (a >= 1 && a <= 9) {
        v[i + 1] = (v[i + 1] + v[i]) % 1000000;
      }
      if (b >= 10 && b <= 26) {
        v[i + 1] = (v[i + 1] + v[i - 1]) % 1000000;
      }
      if (a == 0 && !(b >= 1 && b <= 26)) {
        break;
      }
    }

    cout << v[n.size()];
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
