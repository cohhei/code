#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool check(vector<P> s) {
  int h = 0;
  for (P p : s) {
    int b = h + p.first;
    if (b < 0) return false;
    h += p.second;
  }
  return true;
}
int main() {
  int n;
  cin >> n;

  int total = 0;
  vector<P> ls, rs;
  rep(i, n) {
    string s;
    cin >> s;
    int hight = 0, bottom = 0;
    for (char c : s) {
      if (c == '(')
        ++hight;
      else
        --hight;
      bottom = min(bottom, hight);
    }
    if (hight > 0)
      ls.emplace_back(bottom, hight);
    else
      rs.emplace_back(bottom - hight, -hight);
    total += hight;
  }
  sort(ls.rbegin(), ls.rend());
  sort(rs.rbegin(), rs.rend());
  if (check(ls) && check(rs) && total == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}