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
  int j;
};

int v[500001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N, M;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> v[i];

  sort(v, v + N);

  cin >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;

    int fi = 1e9, se = 1e9;

    int lt = 0, rt = N - 1;
    while (lt <= rt) {
      int mid = (lt + rt) / 2;
      if (v[mid] >= a) {
        rt = mid - 1;
        fi = min(fi, mid);
      } else
        lt = mid + 1;
    }

    lt = 0, rt = N - 1;
    while (lt <= rt) {
      int mid = (lt + rt) / 2;
      if (v[mid] > a) {
        rt = mid - 1;
        se = min(se, mid);
      } else
        lt = mid + 1;
    }

    fi = a > v[N - 1] ? N : fi;
    se = a >= v[N - 1] ? N : se;
    cout << se - fi << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}