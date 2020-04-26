#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<string> bs;
  ll mx = 20000;
  for (ll i = 1; i <= mx; i++) bs.push_back(to_string(2019 * i));

  ll ans = 0;
  for (string sub : bs) {
    int size = sub.size();
    for (int i = 0; i < n; i++) {
      // printf("s: %s, sub: %s, strncmp: %d\n", &s[i], sub.c_str(),
      //        strncmp(&s[i], sub.c_str(), size));
      if (!strncmp(&s[i], sub.c_str(), size)) ans++;

      // int pos = s.find(sub);
      // while (pos != string::npos) {
      //   pos = s.find(sub, pos + size);
      //   ans++;
    } 
  }
  // rep(i, n - 3) {
  //   for (int j = i + 3; j < n; j++) {
  //     string sub = s.substr(i, j - i + 1);
  //     if (stoll(sub) % 2019 == 0) ans++;
  //   }
  // }
  std::cout << ans << endl;
  return 0;
}