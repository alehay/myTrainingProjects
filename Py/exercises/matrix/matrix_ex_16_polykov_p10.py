"""
задание 16 глава матрицы ст.88 учебник полякова 
напишите программу которая заполняет матрицу размером 7*7
случаными числами а затем записывает ноль в элементы отмечены 
на рисунках фоном число ноль. 

трреугольник , ромб 

заметки по решению :
"""
import random

def printMatrix ( A ):
    for i in range(len(A)):
        for j in range(len(A[i])):
            print ("{:3d}".format(A[i][j]), end ="")
        print() #для перевода на новую строку. 

N = int(input("введите количество строк и столбцов: "))

i = N
j = N
difference = 0

matrix = [[0]*j for i in range(N)]
for i in range (N):
    for j in range(N):
        matrix [i][j] = random.randint ( 2, 99)

printMatrix (matrix)

for i in range (N):
    if i <= (N-1)/2  :
            difference = difference + 1
                
    elif i > (N-1)/2 :
            difference = difference  - 1
    
    for j in range(N):                 
        if j > ((N-1)/2 - difference) and j < ((N-1)/2 + difference):
            matrix [i][j] = 0

print()
printMatrix (matrix)