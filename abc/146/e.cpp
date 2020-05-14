#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i]--;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = (s[i] + a[i]) % k;
  map<int, int> mp;
  ll ans = 0;
  rep(i, n + 1) {
    ans += mp[s[i]];
    mp[s[i]]++;
    if (i - k + 1 >= 0) mp[s[i - k + 1]]--;
  }
  cout << ans << endl;
  return 0;
}