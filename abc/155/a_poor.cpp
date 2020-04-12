#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "No";
  if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
    ans = "Yes";
  cout << ans << endl;
  return 0;
}