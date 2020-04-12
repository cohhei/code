#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b;
  cin >> a >> b;
  string as = "", bs = "";
  rep(i, b) as += to_string(a);
  rep(i, a) bs += to_string(b);
  string ans = as < bs ? as : bs;
  cout << ans << endl;
  return 0;
}