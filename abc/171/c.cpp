#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  ll n;
  cin >> n;
  string ans = "";
  rep(i, 10000) {
    n--;
    ll a = n % 26;
    char c = 'a' + a;
    ans.push_back(c);
    n /= 26ll;
    if (n <= 0) break;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}