#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// map<ll, ll> t;
ll turns(ll h)
{
  // if (t[h])
  //   return t[h];
  if (h == 1)
    return 1;
  return /*t[h] = */turns(h / 2) * 2 + 1;
}

int main()
{
  ll h;
  cin >> h;
  cout << turns(h) << endl;
  return 0;
}