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

const int SIZE = 45;
int num[SIZE];

// Fisher–Yates shuffle
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  srand((unsigned)time(NULL));

  for (int i = 0; i < SIZE; i++)
    num[i] = i + 1;

  // 마지막 인덱스부터 값 배정
  // (맨 처음 인덱스 교환할 필요 없음(i<=6)이 아니라 (i<6))
  for (int i = 1; i <= 6; i++)
    swap(num[SIZE - i], num[rand() % (SIZE - i + 1)]);

  for (int i = SIZE - 6; i < SIZE; i++)
    cout << num[i] << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}