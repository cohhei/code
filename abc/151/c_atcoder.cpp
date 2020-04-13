#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ac(n), wa(n);
  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;
    p--;

    if (s == "AC")
      ac[p] = 1;
    else if (!ac[p])
      wa[p]++;
  }
  int ans1 = 0, ans2 = 0;
  rep(i, n) {
    ans1 += ac[i];
    if (ac[i]) ans2 += wa[i];
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}