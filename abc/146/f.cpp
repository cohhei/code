#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  stack<int> st;
  int now = n;
  while (1) {
    if (now <= m) {
      st.push(now);
      break;
    }
    for (int j = m; j >= 0; j--) {
      if (j == 0) {
        cout << -1 << endl;
        return 0;
      }
      if (s[now - j] == '0') {
        now -= j;
        st.push(j);
        break;
      }
    }
  }
  while (1) {
    cout << st.top();
    st.pop();
    if (st.empty()) break;
    cout << " ";
  }
  cout << endl;
  return 0;
}