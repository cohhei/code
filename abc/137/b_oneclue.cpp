#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, x;
  cin >> k >> x;
  for (int i = x - k + 1; i < k + x; i++) cout << i << endl;

  return 0;
}