#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int ans = 0;
  rep(i, n - 1) {
    for (int j = i + 1; j < n; j++) ans += d[i] * d[j];
  }
  cout << ans << endl;
  return 0;
}