#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}
const ll INF = 1e22;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> ans(n);
  rep(i, n) {
    if (i % 2 == 0)
      ans[0] += a[i];
    else
      ans[0] -= a[i];
  }
  for (int j = 1; j < n; j++) {
    ans[j] = a[j - 1] * 2 - ans[j - 1];
  }

  print_vec(ans);
  return 0;
}