
"""
примеры и приемы работы с матрицамирасмотренные в учебнике полякова
"""
from random import randint

#вывод матрицы в "классическом стиле програмирования" 
def printMatrix ( A ):
    for i in range(len(A)):
        for j in range(len(A[i])):
            print ("{:4d}".format(A[i][j]), end ="")
        print() #для перевода на новую строку. 

def pythonStylePrintMatrix ( A ): 
    for row in A:
        for x in row:
            print ("{:4d}".format(x), end ="")
        print ()

# матрица в Python сиписок списков 
A = [[-1, 0, 1],
     [-1, 0, 1],
     [0,  1,-1]]
print (A)
printMatrix(A)

# вариант заполнения без генератора 
N = 3
M = 5
B = []
for i in range(N):
    B.append([0]*M)
print (B)
pythonStylePrintMatrix (B)
# заполнение генератором
C = [[0]*M for i in range(N)]
print (C)


# заполение рандомом

