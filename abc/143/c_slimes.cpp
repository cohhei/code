#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  char now = '#';
  int ans = 0;
  rep(i, s.size()) {
    if (now != s[i]) ans++;
    now = s[i];
  }
  cout << ans << endl;
  return 0;
}