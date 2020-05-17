#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  string ans = "Yes";
  rep(i, s.size()) {
    if (i % 2 == 0) {
      if (s[i] == 'L') {
        ans = "No";
        break;
      }
    } else {
      if (s[i] == 'R') {
        ans = "No";
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}