#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll gcd(ll a, ll b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = lcm(a, b);
  cout << ans << endl;
  return 0;
}