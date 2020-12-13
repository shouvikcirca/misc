import time
import os

mat = [
        [" "," "," "," "," ","0"," "," "," "," "," "],
        [" "," "," "," ","0"," ","0"," "," "," "," "],
        [" "," "," ","0"," "," "," ","0"," "," "," "],
        [" "," ","0"," "," "," "," "," ","0"," "," "],
        [" ","0"," "," "," "," "," "," "," ","0"," "],
        ["0"," "," "," "," "," "," "," "," "," ","0"],
        ["0"," "," "," "," "," "," "," "," "," ","0"],
        [" ","0"," "," "," "," "," "," "," ","0"," "],
        [" "," ","0"," "," "," "," "," ","0"," "," "],
        [" "," "," ","0"," "," "," ","0"," "," "," "],
        [" "," "," "," ","0"," ","0"," "," "," "," "],
        [" "," "," "," "," ","0"," "," "," "," "," "]
      ]


def animate():
    for i in range(len(mat[0])):
            for k in range(len(mat)):
                for j in range(i+1):
                    print(mat[k][j], end = '')
                print()
            time.sleep(0.1)
            if i < (len(mat[0]) - 1):
                os.system('clear')


def animatefix():
    global mat
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            mat[i].append(mat[i][j])

def go():
    for i in range(4):
        animatefix()

go()
for i in range(2):
    animate()
    os.system('clear')



