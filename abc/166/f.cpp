#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1e5 + 1;
char ans[MAX_N];
string s[MAX_N];

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  rep(i, n) cin >> s[i];

  rep(i, n) {
    if (s[i] == "AB") {
      if (a > b) {
        ans[i] = 'B';
        b++;
        a--;
      } else {
        ans[i] = 'A';
        a++;
        b--;
      }
    } else if (s[i] == "AC") {
      if (a > c) {
        ans[i] = 'C';
        c++;
        a--;
      } else {
        ans[i] = 'A';
        a++;
        c--;
      }
    } else if (s[i] == "BC") {
      if (b > c) {
        ans[i] = 'C';
        c++;
        b--;
      } else {
        ans[i] = 'B';
        b++;
        c--;
      }
    }
    if (a < 0 || b < 0 || c < 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  rep(i, n) cout << ans[i] << endl;
  return 0;
}