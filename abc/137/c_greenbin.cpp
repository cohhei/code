#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll choose2(ll n) { return n * (n - 1) / 2; }

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  map<string, ll> freq;
  rep(i, n) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    freq[s[i]]++;
  }
  ll ans = 0;
  for (auto p : freq) {
    if (p.second < 2) continue;
    ans += choose2(p.second);
  }
  cout << ans << endl;
  return 0;
}