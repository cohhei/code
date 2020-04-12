#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(h.rbegin(), h.rend());
  ll sum = 0;
  for (ll i = k; i < n; i++)
  {
    sum += h[i];
  }
  cout << sum << endl;

  return 0;
}