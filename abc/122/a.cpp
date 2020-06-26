#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string c;
  cin >> c;
  map<string, string> m;
  m["A"] = "T";
  m["T"] = "A";
  m["G"] = "C";
  m["C"] = "G";
  string ans = m[c];
  cout << ans << endl;
  return 0;
}