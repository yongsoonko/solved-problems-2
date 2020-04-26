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

int L, C;
char A[15], B[15];
bool D[15];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> L >> C;

  for (int i = 0; i < C; i++)
    cin >> A[i];

  // 순서를 먼저 정렬한 후, 아래에서 조합을 수행함
  sort(A, A + C);

  // // 뒤에서부터 1을 L개 채운다.(순열에서 제일 처음)
  // for (int i = 1; i <= L; i++)
  //   D[C - i] = 1;

  // 앞에서 1을 L개 채운다.(순열에서 제일 마지막)
  for (int i = 0; i < L; i++)
    D[i] = 1;

  do {
    int mcnt = 0, jcnt = 0;
    for (int i = 0; i < C; i++)
      if (D[i]) {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' ||
            A[i] == 'o' || A[i] == 'u')
          mcnt++;
        else
          jcnt++;
      }
    if (mcnt >= 1 && jcnt >= 2) {
      for (int i = 0; i < C; i++)
        if (D[i])
          cout << A[i];
      cout << '\n';
    }
  } while (prev_permutation(D, D + C));

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}