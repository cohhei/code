#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool d = (a + b + c) >= 22;
  string ans = d ? "bust" : "win";
  cout << ans << endl;
  return 0;
}