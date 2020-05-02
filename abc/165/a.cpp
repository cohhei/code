#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  for (int i = 1; i * k <= b; i++) {
    if (a <= i * k && i * k <= b) {
      cout << "OK" << endl;
      return 0;
    }
  }
  cout << "NG" << endl;

  return 0;
}