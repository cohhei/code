#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> ans;
  if (n % 2) {
    for (int l = 1, r = n - 1; l < r; l++, r--) {
      ans.push_back(P(l, r));
    }
  } else {
    bool flag = false;
    for (int l = 1, r = n - 1; l < r; l++, r--) {
      if (!flag && r - l <= n / 2) {
        --r;
        flag = true;
      }
      ans.push_back(P(l, r));
    }
  }
  rep(i, m) { printf("%d %d\n", ans[i].first, ans[i].second); }
  return 0;
}
