import time,os


def zero():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0]
	  	 ]
	return li



def one():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li

def two():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,1,0,0,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li


def three():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,1,1,0,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li

def four():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,1,0,0],
	  	 [0,1,1,0,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li



def five():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,1,0,0],
	  	 [0,1,1,1,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li


def six():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,0,0],
	  	 [0,0,1,1,0],
	  	 [0,1,1,1,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li




def seven():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,1,0],
	  	 [0,0,1,1,0],
	  	 [0,1,1,1,0],
	  	 [1,1,1,1,1]
	  	 ]
	return li




def eight():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,1,0],
	  	 [0,0,1,1,0],
	  	 [0,1,1,1,1],
	  	 [1,1,1,1,1]
	  	 ]
	return li


def nine():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,1,0],
	  	 [0,0,1,1,1],
	  	 [0,1,1,1,1],
	  	 [1,1,1,1,1]
	  	 ]
	return li




def ten():
	li = [
		 [0,0,0,0,0],
	  	 [0,0,0,1,1],
	  	 [0,0,1,1,1],
	  	 [0,1,1,1,1],
	  	 [1,1,1,1,1]
	  	 ]
	return li



def eleven():
	li = [
		 [0,0,0,0,1],
	  	 [0,0,0,1,1],
	  	 [0,0,1,1,1],
	  	 [0,1,1,1,1],
	  	 [1,1,1,1,1]
	  	 ]
	return li




funclist = [zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,ten,nine,eight,seven,six,five,four,three,two,one,zero]




def do():
	for thing in funclist:
		for j in range(20):
				print()
		print("                                       "+"__________________________________\n")
		for row in thing():
			# for j in range(60):

			print("                                      |            ",end="")
			for item in row:
				if item == 1:
					print('| ',end="")
				else:
					print('  ',end="")
			print("            |",end="")
			print()
		print("                                       "+"__________________________________")
		time.sleep(0.03)
		os.system('clear')






for i in range(100):
	do()