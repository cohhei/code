#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  map<string, int> m;
  rep(i, n)
  {
    string s;
    cin >> s;
    m[s]++;
  }
  int mx = 0;
  for (auto p : m)
    mx = max(mx, p.second);
  for (auto p : m)
  {
    if (p.second != mx)
      continue;
    cout << p.first << endl;
  }
  return 0;
}