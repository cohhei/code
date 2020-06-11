#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  ll ans = 0;
  rep(l, k + 1) {
    rep(r, k - l + 1) {
      if (l + r > n) break;
      int d = k - l - r;
      ll now = 0;
      vector<int> s;
      rep(i, l) {
        now += v[i];
        s.push_back(v[i]);
      }
      for (int i = n - r; i < n; i++) {
        now += v[i];
        s.push_back(v[i]);
      }
      sort(s.begin(), s.end());
      rep(i, d) {
        if (i >= s.size()) break;
        if (s[i] > 0) break;
        now -= s[i];
      }
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}