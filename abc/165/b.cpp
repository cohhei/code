#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;
  ll m = 100;
  // int i = 0;
  for (ll i = 0; 1; i++) {
    m *= 1.01;
    if (m >= x) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}