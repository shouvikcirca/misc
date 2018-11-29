import random


numberofobservations = 71
rangeofvalues = 40

observations =[random.randint(1,rangeofvalues) for i in range(numberofobservations)]
histmatrix = [[0 for i in range(numberofobservations)]for j in range(rangeofvalues)]




for i in range(numberofobservations):
	for j in range(rangeofvalues):
		newi = rangeofvalues-1-observations[i]
		if j<=newi:
			histmatrix[j][i]=0
		else:
			histmatrix[j][i]=1






# print (observations)
for i in histmatrix:
	for j in i:
		if j==1:
			print ("| ",end="")
		else:
			print ("  ",end="")
	print()