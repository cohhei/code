#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int l = a.size();
  int ans;
  if (l % 2 == 1) {
    int ma = a[l / 2];
    int mb = b[l / 2];
    ans = mb - ma + 1;
  } else {
    double ma = a[l / 2] + a[l / 2 - 1];
    double mb = b[l / 2] + b[l / 2 - 1];
    ans = mb - ma + 1;
  }
  cout << ans << endl;
  return 0;
}