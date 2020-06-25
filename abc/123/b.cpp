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
  vector<int> a(5);
  int mn = 10, l = 0;
  rep(i, 5) {
    cin >> a[i];
    if ((a[i] - 1) % 10 < mn) {
      mn = (a[i] - 1) % 10;
      l = i;
    }
  }
  rep(i, 5) {
    if (i == l) continue;
    if (a[i] % 10 == 0) continue;
    a[i] += 10 - (a[i] % 10);
  }
  int ans = 0;
  rep(i, 5) ans += a[i];
  cout << ans << endl;
  return 0;
}