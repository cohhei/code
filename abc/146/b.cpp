#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int m = s.size();
  rep(i, m) {
    if (s[i] + n <= 'Z')
      s[i] += n;
    else
      s[i] -= 26 - n;
  }
  cout << s << endl;
  return 0;
}