#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

int main()
{
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        ans += gcd(gcd(i, j), k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}