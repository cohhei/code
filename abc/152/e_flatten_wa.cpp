#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const
  {
    return pow(mod - 2);
  }
  mint &operator/=(const mint a)
  {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};

vector<vector<ll>> g(100);
vector<vector<ll>> l(100);
ll gcd(ll a, ll b)
{
  if (g[a][b])
    return g[a][b];
  if (g[b][a])
    return g[b][a];

  if (a < b)
  {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return g[a][b] = b ? gcd(b, a % b) : a;
}


ll lcm(ll a, ll b)
{
  cout << "a" << endl;
  if (l[a][b])
    return l[a][b];
  if (l[b][a])
    return l[b][a];
  cout << "b" << endl;
  return l[a][b] = a * b / gcd(a, b);
}

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  if (n == 1)
  {
    cout << a[0] % mod << endl;
    return 0;
  }
  ll lc = lcm(a[0], a[1]);
  for (int i = 2; i < n; i++)
    lc = lcm(lc, a[i]);

  mint ans = 0;
  rep(i, n) ans += lc / a[i];
  cout << ans.x << endl;
  return 0;
}