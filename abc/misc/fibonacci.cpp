#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> fib(n + 1);
  fib[0] = 1;
  fib[1] = 1;
  rep(i, n - 1) fib[i + 2] = fib[i + 1] + fib[i];
  cout << fib[n] << endl;
  return 0;
}