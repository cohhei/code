#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, mx = 0, mn = 100, sum = 0;
  cin >> n;
  vector<int> x(n);
  rep(i, n)
  {
    cin >> x[i];
    mx = max(mx, x[i]);
    mn = min(mn, x[i]);
    sum += x[i];
  }
  int p = (double)sum / n + 0.5;
  int ans = 0;
  rep(i, n) ans += (x[i] - p) * (x[i] - p);
  cout << ans << endl;
  return 0;
}