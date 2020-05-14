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
  queue<int> q;
  rep(i, n + 1) {
    ans += mp[s[i]];
    mp[s[i]]++;
    q.push(s[i]);
    if (q.size() == k) {
      mp[q.front()]--;
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}