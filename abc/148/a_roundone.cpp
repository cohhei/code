#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  rep(i, 3) {
    int ii = i + 1;
    if (ii != a && ii != b) cout << ii << endl;
  }
  return 0;
}