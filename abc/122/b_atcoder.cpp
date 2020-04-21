#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  string t = "ATCG";
  int ans = 0;
  int cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}