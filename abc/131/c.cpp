#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

ll gcd(ll p, ll q)
{
  if (p % q == 0)
    return q;
  return gcd(q, p % q);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll l = lcm(c, d);
  ll ans = b - a;
  ans -= b / c;
  ans -= b / d;
  ans += b / l;
  ans += a / c;
  ans += a / d;
  ans -= a / l;
  cout << ans << endl;

  return 0;
}