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
const int MAX_N = 2000002;
int f[MAX_N];
set<int> st;
map<int, bool> mp;
int mx;
int dd;
void sieve(vector<int> a) {
  f[0] = -1;
  for (int i : a) {
    if (mp[i]) {
      dd++;
      st.erase(i);
      continue;
    }
    if (f[i]) continue;
    st.insert(i);
    mp[i] = true;
    f[i] = i;
    for (ll j = i; j <= mx; j += i)
      if (!f[j]) f[j] = i;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }
  sort(a.begin(), a.end());
  mx = a[n - 1];
  sieve(a);
  int ans = st.size();
  // if (dd > 0) ans -= dd + 1;
  cout << ans << endl;
  return 0;
}