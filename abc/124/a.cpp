#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep(i, 2) {
    if (b > a) swap(a, b);
    ans += a;
    a--;
  }
  cout << ans << endl;
  return 0;
}