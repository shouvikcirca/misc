import numpy as np
import os


mat = np.array([[1,2,2],[4,5,6],[7,8,9]])

vec = np.array([5,6,7])


filenumber = 0
col = 0
for j in vec:
    for i in range(0,mat.shape[0]):
        filenumber+=1
        f = open('mapped/m'+str(filenumber)+'.csv','w')
        f.write('key,value\n'+str(i)+','+str(j*mat[i][col]))
        f.close()

    col+=1



os.system('python3 r0.py')
os.system('python3 r1.py')
os.system('python3 r2.py')


finalmat = []
for i in range(3):
    filename = 'reduced/r'+str(i)+'.txt'
    f = open(filename,'r')
    finalmat.append(int(f.read()))
    f.close()

print(finalmat)



