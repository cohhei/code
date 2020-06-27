#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll mn = min(a, min(b, min(c, min(d, e))));
  ll ans = (n + mn - 1) / mn + 4;
  cout << ans << endl;
  return 0;
}