#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  if (s.size() + 1 != t.size()) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, s.size()) {
    if (s[i] != t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}