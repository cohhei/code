#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  rep(i, 9) {
  int  j = i + 1;
    if (n % j == 0) {
      int ans = n / j;
      if (1 <= ans && ans <=9) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}