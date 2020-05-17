#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double PI = acos(-1);
  double dig_m = 6.0 * m * PI / 180.0;
  double dig_h = (0.5 * m + 30.0 * h) * PI / 180.0;

  double xh = cos(dig_h) * a, yh = sin(dig_h) * a;
  double xm = cos(dig_m) * b, ym = sin(dig_m) * b;
  double ans = sqrt((xh - xm) * (xh - xm) + (yh - ym) * (yh - ym));
  printf("%.10f\n", ans);
  return 0;
}