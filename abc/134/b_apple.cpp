#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n >> d;
  int w = d * 2 + 1;
  int ans = n / w;
  if (n % w > 0) ans++;
  cout << ans << endl;
  return 0;
}