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

const int MAX_N = 2e5 + 1;
multiset<int> rates[MAX_N];
multiset<int> strongest;

int getMax(int i) {
  if (rates[i].size() == 0) return INF;
  return *rates[i].rbegin();
}

void addStrongest(int i) {
  int x = getMax(i);
  if (x == INF) return;
  strongest.insert(x);
}
void delStrongest(int i) {
  int x = getMax(i);
  if (x == INF) return;
  strongest.erase(strongest.find(x));
}

void add(int i, int x) {
  delStrongest(i);
  rates[i].insert(x);
  addStrongest(i);
}
void del(int i, int x) {
  delStrongest(i);
  rates[i].erase(rates[i].find(x));
  addStrongest(i);
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);

  rep(i, n) {
    cin >> a[i] >> b[i];
    add(b[i], a[i]);
  }

  rep(i, q) {
    int c, d;
    cin >> c >> d;
    --c;
    del(b[c], a[c]);
    b[c] = d;
    add(b[c], a[c]);
    int ans = *strongest.begin();
    printf("%d\n", ans);
  }
  return 0;
}