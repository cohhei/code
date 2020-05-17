#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
  } else {
    int mid = n / 2 + 0.5;
    double ans = mid / n;
    printf("%.10f\n", ans);
  }
  return 0;
}