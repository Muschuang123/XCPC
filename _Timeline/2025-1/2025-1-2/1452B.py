# after our addition, he must not be sad.
# case: choose the box which hasn't max blocks.
#     lets all boxes have max blocks.
# but we can't add negative numbers of blocks.
#     so that finally blocks > now blocks.

ttt = int(input())
for _ in range(ttt):
    n = int(input())
    a = [int(x) for x in input().split()]
    sum = 0
    mx = 0
    for i in a:
        sum += i
        mx = max(mx, i)
    k = (sum + n - 2) // (n - 1)
    ans = max(mx, k) * (n - 1) - sum
    print(ans)
