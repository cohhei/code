#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  if (a < 1 || 9 < a || b < 1 || 9 < b) {
    cout << -1 << endl;
    return 0;
  }
  cout << a * b << endl;
  return 0;
}