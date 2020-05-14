#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  if (n % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  string t1 = s.substr(0, n / 2);
  string t2 = s.substr(n / 2, n / 2);
  string ans = t1 == t2 ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}