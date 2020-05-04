#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int t;
  cin >> t;
  vector<int> ns(t);
  rep(i, t) cin >> ns[i];
  vector<ll> aa(31);
  rep(i, 31) {
    if (i < 1 || i % 2 == 1) continue;
    aa[i] = aa[i - 2] + pow(2, i / 2);
    // printf("%d %lld %lld\n", i, aa[i], aa[i / 2]);
  }

  for (int n : ns) {
    cout << aa[n] << endl;
  }
  return 0;
}