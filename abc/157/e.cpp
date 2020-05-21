#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

set<int> alphabets[27];

int main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i, n) alphabets[s[i] - 'a'].insert(i);

  int q;
  cin >> q;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int iq;
      char c;
      cin >> iq >> c;
      iq--;
      alphabets[s[iq] - 'a'].erase(iq);
      s[iq] = c;
      alphabets[s[iq] - 'a'].insert(iq);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int ans = 0;
      rep(j, 26) {
        auto it = alphabets[j].lower_bound(l);
        if (it != alphabets[j].end() && *it <= r) ans++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
