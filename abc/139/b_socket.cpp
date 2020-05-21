#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  int ans = b / a;
  if (b % a > 0) ans++;
  cout << ans << endl;
  return 0;
}