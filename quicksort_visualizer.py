import os
import time
import random

def swap(array, a, b):
    temp = array[a]
    array[a] = array[b]
    array[b] = temp

def partition(array, p, q, histmatrix):
    pivot = q
    i = p-1

    for j in range(p,pivot):
        if array[j]>array[pivot]:
            i+=1
            swap(array, i, j)
            time.sleep(0.1)
            os.system('clear')
            createAndDisplay(array, histmatrix, width, height)

    swap(array, i+1, pivot)
    return i+1

def qs(array, f, l):
    if f<l:
        histmatrix = [[0 for i in range(width)]for j in range(height)]
        p = partition(array, f, l, histmatrix)
        histmatrix = [[0 for i in range(width)]for j in range(height)]
        time.sleep(0.3)
        os.system('clear')
        createAndDisplay(array, histmatrix, width, height)
        #a = input('Press Enter')
        qs(array, f, p-1)
        qs(array, p+1, l)

def quickSort(array):
    qs(array, 0, len(array)-1)
    return array


def createAndDisplay(observations, histmatrix, numberofobservations, rangeofvalues):
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

height = 30
width = 30
di = {}
array = []
i = 0

while i<width:
    num = random.randint(1,height)
    if num in di:
        continue
    else:
        i+=1
        di[num] = 1
        array.append(num)

array = quickSort(array)
