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
  int n, l;
  cin >> n >> l;
  int r = n + l - 1;
  int ans = 0;
  for (int i = l; i <= r; i++) ans += i;
  if (r < 0) ans -= r;
  if (l > 0) ans -= l;
  cout << ans << endl;
  return 0;
}