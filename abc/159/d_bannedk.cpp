#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll choose2(ll n)
{
  return n * (n - 1) / 2;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  // rep(i, n) a[i]--;
  vector<int> cnt(n);
  rep(i, n) cnt[a[i]]++;
  cout << "size: " << cnt.size() << endl;
  ll total = 0;
  rep(i, n)
  {
    total += choose2(cnt[i]);
  }
  cout << "total: " << total << endl;

  rep(i, n)
  {
    printf("i: %d, a[i]: %d, cnt[a[i]]: %d\n", i, a[i], cnt[a[i]]);
  }

  rep(k, n)
  {
    ll ans = total - choose2(cnt[a[k]]) + choose2(cnt[a[k]] - 1);
    cout << ans << endl;
  }
  return 0;
}