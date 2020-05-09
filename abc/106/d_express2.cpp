#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int sum[500][500];

// TLEなる
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    for (int j = l; j < n; j++)
      for (int k = r; k < n; k++) sum[j][k]++;
  }

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = sum[r][r];

    if (l > 0) {
      ans -= sum[l - 1][r];
      ans -= sum[r][l - 1];
      ans += (sum[l - 1][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
