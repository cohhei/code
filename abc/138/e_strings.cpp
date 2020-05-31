#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();
  vector<vector<int> > st(26);
  for (int i = 0; i < n; i++) {
    char c = s[i];
    st[c - 'a'].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    char c = s[i];
    st[c - 'a'].push_back(i + n);
  }

  int p = 0;
  ll ans = 0;
  rep(i, m) {
    int c = t[i] - 'a';
    if (st[c].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    p = *lower_bound(st[c].begin(), st[c].end(), p) + 1;
    if (p >= n) {
      p -= n;
      ans += n;
    }
  }
  ans += p;
  cout << ans << endl;
  return 0;
}