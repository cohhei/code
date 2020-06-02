#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  rep(i, n) {
    int b;
    cin >> b;
    a[i] = P(b, i);
  }
  sort(a.begin(), a.end());
  vector<int> ans(n);
  P mx = a[n - 1], sc = a[n - 2];
  ans[mx.second] = sc.first;
  rep(i, n - 1) {
    P p = a[i];
    ans[p.second] = mx.first;
  }
  rep(i, n) cout << ans[i] << endl;
  return 0;
}