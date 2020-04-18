#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  a = a - k;
  if (a < 0) {
    b = a + b;
    b = b < 0 ? 0 : b;
  }
  a = a < 0 ? 0 : a;
  cout << a << " " << b << endl;
  return 0;
}