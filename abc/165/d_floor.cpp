#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
// https://atcoder.jp/contests/abc165/tasks/abc165_d
int main() {
  // 除算の切り捨てfloor(x)
  // e.g. floor(a/b) = (a - a % b) / b 割り切れない分を先に引いておく感じ

  // ((A*x - A*x % B) - (A * (x - x%B)) ) / b
  // (A*x - A*x % B) - (A * (x - x%B)) が最大となるx
  // = Ax - Ax % B - Ax + A(x%B)
  // = A(x%B) - Ax%B
  // = A(x % B)
  // x%B が最大となるx を求めればいい

  // x = pB + q (0<=q<B) と考えると (Aq)/B になる

  ll a, b, n;
  cin >> a >> b >> n;
  ll x = min(n, b - 1);
  ll ans = a * (x % b) / b;
  cout << ans << endl;
  return 0;
}