#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll st = 1;
  ll en = 1e9;
  while (en >= st) {
    ll mid = (en + st) / 2;
    if (a * mid + to_string(mid).size() * b > x)
      en = mid - 1;
    else
      st = mid + 1;
  }
  cout << en << endl;
  return 0;
}