#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a;
    cin >> a;
    n -= a;
  }
  if (n < 0) n= -1;
  cout << n << endl;
  return 0;
}