import time
import matplotlib.pyplot as plt
import numpy as np


dp=[]
nodp = []

def retsum(n,li):
  if n==0:
    return 0
  elif n==1:
    return 1
  elif li[n-1]>0:
    return li[n-1]
  else:
    li[n-1] = retsum(n-1,li)+retsum(n-2,li)
    return li[n-1]


def retsumone(n,li):
  if n==0:
    return 0
  elif n==1:
    return 1
  else:
    return retsumone(n-1,li) + retsumone(n-2,li)





for n in range(20):
  a = time.time()
  ss=retsum(n,[-1 for i in range(n)])
  b = time.time()
  dp.append((b-a))

# No dynamic programming
#print ("\n\n\n\nNo dynamic programming")

  c = time.time()
  ss=retsumone(n,[-1 for i in range(n)])
  d = time.time()
  nodp.append((d-c))





# Visualization
dp, = plt.plot(dp, color = 'r', label = 'dp')
nodp, = plt.plot(nodp, color = 'b', label = 'nodp')
plt.legend(handles=[dp,nodp])
plt.show()




comp = np.zeros(len(dp))
for i in range(len(dp)):
	comp[i] = (dp[i] > nodp[i])






print('{}'.format(np.sum(comp)/len(comp)))





