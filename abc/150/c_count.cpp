#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void dfs(int i, int n, vector<int> r, vector<vector<int>>* res) {
  if (r[n - 1] > 0) {
    res->push_back(r);
    return;
  }
  for (int j = 1; j <= n; j++) {
    bool con = false;
    for (int k = 0; k <= i; k++) {
      if (r[k] == j) {
        con = true;
        continue;
      }
    }
    if (con) continue;
    r[i] = j;
    dfs(i + 1, n, r, res);
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  int a, b;
  vector<int> r(n, 0);
  vector<vector<int>> res;
  dfs(0, n, r, &res);
  rep(i, res.size()) {
    if (p == res[i]) a = i;
    if (q == res[i]) b = i;
  }
  int ans = a > b ? a - b : b - a;
  cout << ans << endl;
  return 0;
}