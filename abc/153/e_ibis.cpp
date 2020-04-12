#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
// ※とけません。
int main()
{
  ll h, n;
  cin >> h >> n;
  vector<ll> a(n), b(n);
  vector<double> c(n);
  ll mx = 0, mn = 10000;
  ll j, k;
  rep(i, n)
  {
    cin >> a[i] >> b[i];
    c[i] = a[i] / b[i];
    if (mx < c[i])
    {
      mx = c[i];
      j = i;
    }
  }
  ll ans = (h / a[j]) * b[j];
  ll remain = h % a[j];
  if (remain > 0)
  {
    rep(i, n)
    {
      if (remain <= a[i])
      {
        mn = min(mn, b[i]);
      }
      else
      {
        ll t = (remain / a[i] + 1);
        ll sum = t * b[i];
        mn = min(mn, sum);
      }
    }
    ans += mn;
  }
  cout << ans << endl;
  return 0;
}