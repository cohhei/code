#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int ans = 0;
  rep(i, n) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}