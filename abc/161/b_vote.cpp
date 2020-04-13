#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  std::vector<int> a(n);

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.rbegin(), a.rend());
  string ans = "Yes";
  if (a[m - 1] < (double)sum / (4 * m))
  {
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}
