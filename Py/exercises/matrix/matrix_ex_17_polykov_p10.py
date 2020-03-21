"""
задание 17 глава матрицы ст.88 учебник полякова 

заполните матрицу, содержащую N строк и M столбцов натуральными числами 

вариант 1               вариант 2           вариант 3

1   2   3   4           1   4   7   10      10  7   4   1

5   6   7   8           2   5   8   11      11  8   5   2

9   10  11  12          3   6   9   12      12  9   6   3


заметки по решению :
"""

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
N=3 #3
M=4 #4
matrix_1 = []
num = 1
matrix_1 = [[0]*M for i in range(N)]

for i in range(N):
    for j in range(M):
        matrix_1 [i][j] = num
        num +=1
printMatrix (matrix_1)

printSeparator ("*","matrix2")

num = 1 
for j in range (M):
    for i in range (N):
        matrix_1 [i][j] = num
        num +=1
printMatrix (matrix_1)

printSeparator ("*","matrix3")

num = 1 
for j in range (M-1,-1,-1):
    for i in range(N):
        matrix_1 [i][j] = num
        num +=1
printMatrix (matrix_1)

#COMPLETE