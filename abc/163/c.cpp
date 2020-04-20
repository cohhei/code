#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> ans(n);
  rep(i, n - 1) {
    int a;
    cin >> a;
    ans[a - 1]++;
  }
  rep(i, n) cout << ans[i] << endl;
  return 0;
}