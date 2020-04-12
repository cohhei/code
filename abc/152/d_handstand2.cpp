#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

P make_p(int x)
{
  int tail = x % 10;
  int head = to_string(x)[0] - '0';
  return P(tail, head);
}

int main()
{
  int n;
  cin >> n;
  map<P, int> freq;
  for (int i = 1; i <= n; i++)
  {
    P p = make_p(i);
    freq[p]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    P p = make_p(i);
    P q = P(p.second, p.first);
    ans += freq[q];
  }
  cout << ans << endl;
  return 0;
}