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
  int n;
  cin >> n;
  vector<int> w(n);
  rep(i, n) {
    cin >> w[i];
    if (i > 0) w[i] += w[i - 1];
  }

  int ans = INF;
  rep(i, n) {
    int a = w[i];
    int b = w[n-1] - w[i];
    ans = min(ans, abs(b - a));
  }
  cout << ans << endl;
  return 0;
}