#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<char, char>;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  // int ans = 0;
  vector<int> freq(3);
  rep(i, n)
  {
    int j = 0;
    if (s[i] == 'G')
      j = 1;
    else if (s[i] == 'B')
      j = 2;
    freq[j]++;
  }
  ll ans = 1;
  rep(i, 3) ans *= freq[i];

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      int k = j + (j - i);
      if (k >= n)
        continue;

      if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k])
      {
        ans--;
      }
    }
  }

  cout << ans << endl;

  return 0;
}