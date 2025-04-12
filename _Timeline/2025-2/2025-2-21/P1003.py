n = int(input())
a = [0] * n
b = [0] * n
g = [0] * n
k = [0] * n
for i in range(n):
    a[i], b[i], g[i], k[i] = [int(i) for i in input().split(" ")]
x, y = [int(i) for i in input().split(" ")]

ans = -1
for i in range(n):
    if a[i] <= x and a[i] + g[i] >= x and b[i] <= y and b[i] + k[i] >= y:
        ans = i + 1

print(ans)
