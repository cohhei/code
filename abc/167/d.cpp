#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> b(n);
  rep(i, n) b[i] = -1;
  ll cnt = 0;
  ll next = 0;
  ll nokori = 0;
  rep(i, k) {
    if (b[next] >= 0) {
      nokori = (k - b[next]) % (cnt - b[next]);
      break;
    } else {
      b[next] = cnt++;
    }
    next = a[next];
  }

  rep(i, nokori) next = a[next];
  cout << next + 1 << endl;
  return 0;
}