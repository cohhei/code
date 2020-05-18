#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int mod = 1000000007;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main() {
  int n;
  cin >> n;
  map<P, P> mp;
  int zero = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      zero++;
      continue;
    }
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    if (y < 0) x = -x, y = -y;
    if (y == 0 && x < 0) x = -x, y = -y;
    bool rot90 = x <= 0;
    if (rot90) {
      swap(x, y);
      y = -y;
    }
    if (rot90)
      mp[P(x, y)].first++;
    else
      mp[P(x, y)].second++;
  }

  mint ans = 1;
  for (auto p : mp) {
    int s = p.second.first;
    int t = p.second.second;
    mint now = 1;
    now += mint(2).pow(s) - 1;
    now += mint(2).pow(t) - 1;
    ans *= now;
  }
  ans -= 1;
  ans += zero;
  cout << ans.x << endl;
  return 0;
}