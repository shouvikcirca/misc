
import os

dirs = os.listdir('mapped')


sum = 0
for file in dirs:
    f = open('mapped/'+file,'r')
    s = f.read().split('\n')[1].split(',')
    if s[0] == '2':
        sum+=int(s[1])
    f.close()

f = open('reduced/r2.txt','w')
f.write(str(sum))
f.close()
