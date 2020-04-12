#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  ll mn = 10000000;
  int ans = 0;
  rep(i, n)
  {
    ll p;
    cin >> p;
    if (p <= mn)
    {
      mn = p;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}