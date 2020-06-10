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
  vector<int> v(3);
  rep(i, 3) cin >> v[i];
  sort(v.begin(), v.end());
  int ans = v[0] + v[1];
  cout << ans << endl;
  return 0;
}