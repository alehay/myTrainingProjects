"""
задание 23 глава матрицы ст.89 учебник полякова 

Заполните матрицу N на M столбцов случаными двоичными значениями (каждый элемент может быть равен 0 или 1 )
и добавте кней еще один столбец ( столбец четности) так что бы количество единиц в каждой строке было четным!

заметки по решению :
"""

import random


def printSeparator ( A, name ):
    print()
    for i in range (3):
        print ( A * 40)
    print()
    print (A *15,name, A*15)
    print ()

def printMatrix ( A ):
    for i in range(len(A)):
        for j in range(len(A[i])):
            print ("{:3d}".format(A[i][j]), end ="")
        print() #для перевода на новую строку. 


N=12 #3 -ограничитель;  i  Y - индексы оси
M=5 #4 -ограничитель;  j  X - индекс оси. 


matrix_1 = [[0]*M for i in range(N)]

printSeparator ("*", "matrix_1")

for i in range (N):
    for j in range(M):
        matrix_1 [i][j] = random.randint ( 0, 1)

printMatrix (matrix_1)

matrix_2 = [[0]*(M+1) for i in range(N)]

printSeparator ("+","matrix_2")
sum = 0

for i in range (N):
    sum = 0
    for j in range (M):
        sum = sum + matrix_1 [i][j]
        matrix_2 [i][j] = matrix_1 [i][j]
    if sum % 2 == 0:
        matrix_2 [i][j+1] = 0
    else:
        matrix_2 [i][j+1] = 1 

printMatrix (matrix_2)
    
# ! COMPLETE