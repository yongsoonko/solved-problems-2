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

bool groupSumClump(int start, vector<int> &arr, int sum) {
  if (sum == 0) {
    return 1;
  } else if (start < arr.size()) {
    int i;
    for (i = start + 1; i < arr.size() && arr[i - 1] == arr[i]; i++) {}
    if (groupSumClump(i, arr, sum) ||
        groupSumClump(i, arr, sum - (i - start) * arr[start]))
      return 1;
    return 0;
  } else  // start >= arr.size()
    return 0;
}

// http://www.javaproblems.com/2013/11/java-recursion-2-groupsumclump.html
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, sum;
  cin >> N;
  vector<int> arr(N);
  for (int &i : arr)
    cin >> i;
  cin >> sum;

  groupSumClump(0, arr, sum) ? cout << "true" : cout << "false";

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}