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
  ll n, k;
  cin >> n >> k;
  vector<ll> sum(n + 1);
  sum[0] = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum[i + 1] = sum[i] + a;
  }
  ll ans = 0;
  rep(i, n + 1) {
    ll lower = lower_bound(sum.begin(), sum.end(), sum[i] + k) - sum.begin();
    ans += n - lower + 1;
  }
  cout << ans << endl;
  return 0;
}