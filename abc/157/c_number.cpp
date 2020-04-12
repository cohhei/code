#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> num(n);

  rep(i, n) num[i] = -1;
  vector<int> s(m);
  vector<int> c(m);
  rep(i, m)
  {
    cin >> s[i] >> c[i];
    s[i]--;
  }
  rep(i, m)
  {
    if (num[s[i]] != -1 && num[s[i]] != c[i])
    {
      cout << -1 << endl;
      return 0;
    }
    num[s[i]] = c[i];
  }
  if (n > 1 && num[0] == -1)
    num[0] = 1;
  if (n > 1 && num[0] == 0)
  {
    cout << -1 << endl;
    return 0;
  }
  rep(i, n) cout << (num[i] == -1? 0: num[i]);
  cout << endl;
  return 0;
}