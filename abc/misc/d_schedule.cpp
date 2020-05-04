#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

const int MOD = 10007;
const int MAX_N = 1010;

int N;
char S[MAX_N];

int dp[MAX_N][8];

void exclude(int pos, int p) {
  for (int i = 0; i < 8; i++)
    if ((i & (1 << p)) == 0) dp[pos][i] = 0;
}

int main() {
  map<char, int> char_to_id;
  char_to_id['J'] = 0;
  char_to_id['O'] = 1;
  char_to_id['I'] = 2;

  scanf("%d%s", &N, S);

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      for (int j = 0; j < 8; j++) dp[i][j] = 1;

      exclude(i, 0);
    } else {
      for (int j = 0; j < 8; j++) dp[i][j] = 0;

      for (int j = 0; j < 8; j++)
        for (int k = 0; k < 8; k++)
          if (j & k) dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
    }

    exclude(i, char_to_id[S[i]]);
  }

  int sol = 0;
  for (int i = 0; i < 8; i++) sol = (sol + dp[N - 1][i]) % MOD;

  printf("%d\n", sol);

  return 0;
}