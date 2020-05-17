#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int m = n % 10;
  if (m == 3)
    cout << "bon";
  else if (m == 0 || m == 1 || m == 6 || m == 8)
    cout << "pon";
  else
    cout << "hon";
  cout << endl;
  return 0;
}