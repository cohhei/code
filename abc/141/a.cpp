#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  if (s == "Sunny")
    s = "Cloudy";
  else if (s == "Rainy")
    s = "Sunny";
  else if (s == "Cloudy")
    s = "Rainy";
  cout << s << endl;
  return 0;
}