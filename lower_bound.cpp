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

vector<int> data = {1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6};
int lower_bound(int lt, int rt, int value) {
  int ret = rt;
  rt--;
  while (lt <= rt) {
    int mid = (lt + rt) / 2;
    // upper_bound는 <=, lower_bound는 <
    if (data[mid] <= value)
      lt = mid + 1;
    else {
      ret = min(ret, mid);
      rt = mid - 1;
    }
  }
  return ret;
}

int upper_bound(int lt, int rt, int value) {
  return lower_bound(lt, rt, value);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int value = -1;
  // cout << *lower_bound(data.begin(), data.end(), value) << '\n'
  //      << data[lower_bound(0, data.size(), value)];

  cout << *upper_bound(data.begin(), data.end(), value) << '\n'
       << data[upper_bound(0, data.size(), value)];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}