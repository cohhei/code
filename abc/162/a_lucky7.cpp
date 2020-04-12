#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string s;
  cin >> s;
  string ans = "No";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '7')
    {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}