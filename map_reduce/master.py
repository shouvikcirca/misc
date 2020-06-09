import numpy as np
import os
import torch


# Matrix
mat = np.array([[1,2,3,4],[4,5,6,7],[7,8,9,3],[9,8,7,1],[8,7,6,8],[7,6,5,5]])
number_of_reducers = mat.shape[0]


# Vector
vec = np.array([5,6,7,2])


# Just change the vector and matrix size not violating the multiplication rule
# If mat has dimensions m*n vec must have dimension n*1



# For creating key, values where key:row of matrix and value:bj*ai,j
filenumber = 0
col = 0
for j in vec:
    for i in range(0,mat.shape[0]):
        filenumber+=1
        f = open('mapped/m'+str(filenumber)+'.csv','w')
        f.write('key,value\n'+str(i)+','+str(j*mat[i][col]))
        f.close()

    col+=1


# Creating reducers that will take on specific keys
for n in range(number_of_reducers):
    f = open('rtemplate.py','r')
    s = f.read()
    s = s.replace("'0'","'"+str(n)+"'")
    s = s.replace('r0.txt','r'+str(n)+'.txt')
    filename = 'r'+str(n)+'.py'
    g = open(filename,'w')
    g.write(s)
    g.close()
    f.close()



# Files to which reducers will write
for e in range(number_of_reducers):
    execline = 'python3 r'+str(e)+'.py'
    os.system(execline)




# Gather data from files reducers have written to
finalmat = []
for i in range(number_of_reducers):
    filename = 'reduced/r'+str(i)+'.txt'
    f = open(filename,'r')
    finalmat.append(int(f.read()))
    f.close()



print(finalmat)



# A pytorch multiplication for verifying results
print(torch.matmul(torch.from_numpy(mat),torch.from_numpy(vec)))


