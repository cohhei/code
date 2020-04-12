#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;

bool a(string s)
{
  for (int i = 0; i < s.size() / 2; i++)
  {
    if (s[i] != s[s.size() - 1 - i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  string ans = "No";
  if (a(s) && a(s.substr(0, (s.size() - 1) / 2)))
  {
    ans = "Yes";
  }

  cout << ans << endl;
  return 0;
}
