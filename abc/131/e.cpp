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
  int lim = (n - 1) * (n - 2) / 2;
  if (k > lim) {
    cout << -1 << endl;
    return 0;
  }
  int m = n * (n - 1) / 2 - k;
  cout << m << endl;
  int cnt = 0;
  rep(i, n - 1) for (int j = i + 1; j < n; j++) {
    if (cnt >= m) break;
    printf("%d %d\n", i + 1, j + 1);
    cnt++;
  }
  return 0;
}