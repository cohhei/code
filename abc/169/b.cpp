#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;

const ll mod = 1e18;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  __int128 ans = 1;
  rep(i, n) {
    ans *= a[i];
    if (ans > mod) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ll(ans) << endl;
  return 0;
}