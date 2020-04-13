#include <iostream>
#include <cstdlib> // abs() for integer
#include <cmath>   // abs() for float, and fabs()
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main()
{
  ll n, k;
  cin >> n >> k;
  n = (n % k);
  if (n > abs(n - k))
  {
    n = abs(n - k);
  }

  cout << n << endl;
  return 0;
}
