#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  int cnt = 0;
  ll sq = sqrt(n) + 1;
  for (int i = 2; i <= sq; i++) {
    if (n % i == 0) {
      n /= i;
      cnt++;
    }
  }
  if (n > 1 && cnt == 0) cnt++;
  cout << cnt << endl;
  return 0;
}