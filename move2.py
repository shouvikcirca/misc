import os, time



for i in range(10):
	print()


def startoff():

	str1=" {}\n"
	str2="{} {}\n"
	str3=" {}"

	
	for i in range(60):
		if i%4 == 0:
			stri=str1.format(0) + str2.format("","") + str3.format("")
		elif i%4 == 1:
			stri=str1.format("") + str2.format("",0) + str3.format("")
		elif i%4 == 2:
			stri=str1.format("") + str2.format("","") + str3.format(0)
		else:
			stri=str1.format("") + str2.format(0,"") + str3.format("")
		for i in range(10):
			print()

		print (stri)
		time.sleep(0.1)
		os.system('clear')
		str1=" "+str1
		str2=" "+str2
		str3=" "+str3


	

for i in range(10000):
	startoff()





