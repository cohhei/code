#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int s, w;
  cin >> s >> w;
  string ans = s > w ? "safe" : "unsafe";
  cout << ans << endl;
  return 0;
}