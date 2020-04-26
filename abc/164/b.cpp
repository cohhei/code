#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (1) {
    c -= b;
    if (c < 1) {
      cout << "Yes" << endl;
      break;
    }
    a -= d;
    if (a < 1) {
      cout << "No" << endl;
      break;
    }
  }
  return 0;
}