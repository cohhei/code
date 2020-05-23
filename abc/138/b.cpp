#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  rep(i, n) {
    int a;
    cin >> a;
    ans += 1.0 / a;
  }
  ans = 1.0 / ans;
  printf("%.10lf\n", ans);
  return 0;
}