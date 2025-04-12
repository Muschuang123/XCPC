ttt = int(input())
for t in range(ttt):
	n = int(input())
	a = [int(x) for x in input().split()]
	start = 0
	if n % 2 == 1:
		if (a[0] + a[1] != 0):
			print(-a[2], -a[2], a[0] + a[1], end = " ")
		elif (a[1] + a[2] != 0):
			print(a[2] + a[1], -a[0], -a[0], end = " ")
		else:
			print(-a[1], a[0] + a[2], -a[1], end = " ")
		start = 3
	while start < n:
		print(-a[start + 1], a[start], end = " ")
		start += 2
	print()