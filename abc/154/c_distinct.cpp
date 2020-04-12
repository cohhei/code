#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  map<ll, int> m;
  string ans = "YES";
  rep(i, n)
  {
    ll a;
    cin >> a;
    if (m[a])
    {
      ans = "NO";
      break;
    }
    m[a]++;
  }
  cout << ans << endl;
  return 0;
}