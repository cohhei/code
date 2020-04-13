using ll = long long;
// if p < q : O(log p)
ll gcd(ll p, ll q)
{
  if (p % q == 0)
    return q;
  return gcd(q, p % q);
}