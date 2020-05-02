#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  double low = 0;
  // 右側
  double high = n + 1;

  auto f = [&](ll i) { return a * i / b - a * (i / b); };
  int cnt = 10000;
  while (--cnt) {
    double c1 = (low * 2 + high) / 3;
    double c2 = (low + high * 2) / 3;
    if (f(c1) <= f(c2))
      low = c1;
    else
      high = c2;
  }
  cout << fixed << setprecision(20) << f(low) << endl;
  return 0;
}