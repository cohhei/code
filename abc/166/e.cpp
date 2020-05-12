#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<ll, ll> minus;
  map<ll, ll> plus;
  int mx = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    minus[i - a]++;
    plus[a + i]++;
  }

  ll ans = 0;
  for (P p : minus) {
    ans += p.second * plus[p.first];
  }
  cout << ans << endl;
  return 0;
}