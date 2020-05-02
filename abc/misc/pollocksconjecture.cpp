#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int ele[1000001];
int dp1[1000001];
int dp2[1000001];

int main() {
  rep(i, 181) ele[i] = (i + 1) * (i + 2) * (i + 3) / 6;
  vector<int> nn;
  while (1) {
    int n;
    cin >> n;
    if (n < 1) break;
    nn.push_back(n);
  }
  memset(dp1, 1, sizeof(dp1));
  memset(dp2, 1, sizeof(dp2));

  dp1[0] = 0;
  dp2[0] = 0;
  rep(i, 1000001) rep(j, 180) {
    if (i + ele[j] > 1000001) break;
    dp1[i + ele[j]] = min(dp1[i + ele[j]], dp1[i] + 1);
    if (ele[j] % 2 == 1) dp2[i + ele[j]] = min(dp2[i + ele[j]], dp2[i] + 1);
  }

  for (int n : nn) {
    printf("%d %d\n", dp1[n], dp2[n]);
  }
  return 0;
}