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
  int n, x;
  cin >> n >> x;
  vector<int> d(n + 1);
  d[0] = 0;
  rep(i, n) {
    int l;
    cin >> l;
    d[i + 1] = d[i] + l;
  }
  int ans = lower_bound(d.begin(), d.end(), x + 1) - d.begin();
  cout << ans << endl;
  return 0;
}