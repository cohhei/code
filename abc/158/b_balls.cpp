#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  ll num = n / (a + b);
  ll mod = n % (a + b);
  ll ext = min(a, mod);
  cout << num * a + ext << endl;

  return 0;
}