#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = -1000000000;
  int loop = n % 2 + 2;
  rep(i, loop)
  {
    ll sum = 0;
    int cnt = 0;
    for (int j = i; cnt < n / 2; j += 2)
    {
      sum += a[j];
      cnt++;
    }
    printf("sum: %ld, cnt: %d\n", sum, cnt);
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}