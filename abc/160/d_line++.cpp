#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;

  vector<int> freq(n);
  rep(i, n) rep(j, n) {
    if (i < j) {
      int dist =
          min(j - i, min(abs(x - i) + 1 + abs(j - y), abs(y - i) + 1 + abs(j - x)));
      freq[dist]++;
    }
  }
  for (int i = 1; i < n; i++) cout << freq[i] << endl;

  return 0;
}