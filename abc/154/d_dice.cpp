#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll k, n;
  cin >> n >> k;
  vector<double> p(n);
  rep(i, n)
  {
    cin >> p[i];
    p[i] = 0.5 * p[i] + 0.5;
    // cout << p[i] << " ";
  }
  // cout << endl;
  double mx = 0;
  double sum = 0;
  rep(i, n - k + 1)
  {
    if (!sum)
      rep(j, k) sum += p[j];
    else
      sum = sum - p[i - 1] + p[i + k - 1];
    // printf("i: %d sum: %lf mx: %lf\n", i, sum, mx);
    mx = max(mx, sum);
  }
  printf("%lf\n", mx);
  return 0;
}