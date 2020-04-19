#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int bad_main() {
  ll n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i * 2 < n; i++) {
    int cnt = 0;
    // string str = to_string(n - i * 2);
    ll now = n - i * 2;
    // cout << str << endl;
    for (int j = 1; 1; j++) {
      if (now % (10 * j) == 0)
        cnt++;
      else
        break;
      // if (str[str.size() - j - 1] == '0')
      //   cnt++;
      // else
      //   break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

ll g1(ll n, int p) {
  if (n == 0) return 0;
  return n / p + g1(n / p, p);
}

ll g2(ll n, int p) {
  if (n % 2 == 1) return g1(n, p) - g2(n - 1, p);
  ll res = g1(n / 2, p);
  if (p == 2) res += n / 2;
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll ans = min(g2(n, 2), g2(n, 5));
  cout << ans << endl;
  return 0;
}