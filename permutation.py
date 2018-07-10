import sys


def permute(str, li, finallist):
	if len(li) == 0:
		return str
	aclen = len(li)
	for i in range(aclen):
		item = li.pop()
		p = permute(str+item, li, finallist) 
		finallist.append(p)
		li.insert(0,item)
	return finallist




def getAllPermutations(str):
	strlist = [str[i] for i in range(len(str))]
	listOfPerms = permute('',strlist,[])
	return [i for i in listOfPerms if len(i) == len(str)]


if len(sys.argv)>2:
	print ('incorrect input')
else:
	permlist = getAllPermutations(sys.argv[1])
	print ('There are {} permutations possible \n {}'.format(len(permlist), permlist))

