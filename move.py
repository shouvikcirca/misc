import os, time



def startoff():
	str1=" _\n"
	str2="|_|"


	ltr1=" _\n"
	ltr2="|_|"


	for i in range(20):
		stri=str1+str2
		ltr=ltr1+ltr2
		print (stri)
		print (ltr)
		time.sleep(0.1)
		os.system('clear')
		str1="\n"+str1
		# str2="\n"+str2
		ltr1=" "+ltr1
		ltr2=" "+ltr2


	for i in range(20):
		stri=str1+str2
		ltr=ltr1+ltr2
		print (stri)
		print (ltr)
		time.sleep(0.1)
		os.system('clear')
		str1=str1[1:]
		# str2="\n"+str2
		ltr1=ltr1[1:]
		ltr2=ltr2[1:]


for i in range(10000):
	startoff()