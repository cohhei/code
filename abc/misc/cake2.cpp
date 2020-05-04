#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 2000;

// dp[i][j] 区間iからjが残っているときの取り分の最大値
ll dp[MAX_N + 1][MAX_N + 1];
int b[MAX_N + 1];
int a;

long long calc(int l, int r, int s) {
  if (~dp[l][r]) return dp[l][r];
  if (l == r) {
    if (s) return dp[l][r] = 0;
    return dp[l][r] = b[l];
  }
  if (s) {
    if (b[l] > b[r]) {
      return dp[l][r] = calc((l + 1) % a, r, 0);
    } else {
      return dp[l][r] = calc(l, (r + a - 1) % a, 0);
    }
  }
  return dp[l][r] = max(calc((l + 1) % a, r, 1) + b[l],
                        calc(l, (r + a - 1) % a, 1) + b[r]);
}

int main() {
  scanf("%d", &a);
  for (int i = 0; i < a; i++) scanf("%d", b + i);
  for (int i = 0; i < MAX_N + 1; i++)
    for (int j = 0; j < MAX_N + 1; j++) dp[i][j] = -1;
  long long ret = 0;
  for (int i = 0; i < a; i++) {
    ret = max(ret, calc((i + 1) % a, (i + a - 1) % a, 1) + b[i]);
  }
  printf("%lld\n", ret);
}