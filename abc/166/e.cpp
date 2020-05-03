#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> freq[1000000001];

int main() {
  int n;
  cin >> n;
  vector<P> h(n);
  int mx = 0;
  rep(i, n) {
    int a;
    cin >> a;
    freq[a].push_back(i);
    mx = max(mx, a);
    h[i] = P(a, i);
  }

  rep(i, mx+1) {
    
  }
   sort(h.begin(), h.end());
  rep(i, n) printf("%2d", h[i].first);
  cout << endl;
  rep(i, n) printf("%2d", h[i].second);
  cout << endl;

  vector<int> diff(n);
  rep(i, n) {}
  return 0;
}