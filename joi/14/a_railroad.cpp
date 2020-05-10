#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1e5;
ll costs[MAX_N];

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  rep(i, m) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> times(n);
  rep(i, m - 1) {
    int l = min(p[i], p[i + 1]);
    int r = max(p[i], p[i + 1]);
    times[l]++;
    times[r]--;
  }
  rep(i, n - 2) times[i + 1] += times[i];

  vector<ll> a(n), b(n), c(n);
  rep(i, n - 1) cin >> a[i] >> b[i] >> c[i];
  ll ans = 0;
  rep(i, n - 1) {
    ans += min(a[i] * times[i], b[i] * times[i] + c[i]);
  }
  cout << ans << endl;
  return 0;
}