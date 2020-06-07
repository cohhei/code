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

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (p[i - 1] < p[i] && p[i] <= p[i + 1])
      ans++;
    else if (p[i + 1] < p[i] && p[i] <= p[i - 1])
      ans++;
  }
  cout << ans << endl;
  return 0;
}