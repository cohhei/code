#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = max(0, c - (a - b));
  cout << ans << endl;
  return 0;
}