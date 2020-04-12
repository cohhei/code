#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if (s == u)
    a--;
  if (t == u)
    b--;
  printf("%d %d\n", a, b);
  return 0;
}