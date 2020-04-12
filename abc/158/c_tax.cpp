#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b;
  cin >> a >> b;
  int amin = a * 12.5 + 0.5;
  int amax = (a + 1) * 12.5 - 0.5;
  int bmin = b * 10;
  int bmax = bmin + 9;
  if (amax < bmin || bmax < amin)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << max(amin, bmin) << endl;
  return 0;
}