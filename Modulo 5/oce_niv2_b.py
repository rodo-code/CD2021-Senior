import math
casos = int(input())
for i in range(0,casos):
	a,b = map(int,input().split())
	na = a
	x = math.log(a,b)
	nb = (b/x)-math.log(x,a)
	if nb<0:
		print("True")
	else:
		nnb = math.log(nb,a)
		if na>nnb:
			print("True")
		else:
			print("False")
