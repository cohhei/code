n = input()
A = list(map(int, input().split()))

limit = 10 ** 18
A.sort()
ans = 1
for a in A:
  ans *= a
  if ans > limit:
    print(-1)
    exit(0)
print(ans)