#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string s;
  cin >> s;
  ll q;
  cin >> q;
  bool rev = false;
  vector<char> str(s.size());
  rep(i, s.size()) str[i] = s[i];
  rep(i, q)
  {
    int op;
    cin >> op;
    if (op == 1)
      rev = !rev;
    else
    {
      int fb;
      cin >> fb;
      char c;
      cin >> c;
      if (fb == 1 && !rev || fb == 2 && rev)
      {
        str.insert(str.begin(), c);
      }
      else
      {
        str.push_back(c);
      }
    }
  }
  if (rev)
    reverse(str.begin(), str.end());
  rep(i, str.size()) printf("%c", str[i]);
  cout << endl;
  return 0;
}