"""
задание 14 глава матрицы ст.88 учебник полякова 
напишите программу которая заполняет матрицу из N строк и N столбцов
нулями и единицами такб что все эелемнты выше главной диагонали равны нулю остальние -единице 

заметки по решению :
"""


def printMatrix ( A ):
    for i in range(len(A)):
        for j in range(len(A[i])):
            print ("{:3d}".format(A[i][j]), end ="")
        print() #для перевода на новую строку. 

N = int(input("введите количество строк и столбцов: "))

i = N
j = N

matrix = [[1]*j for i in range(N)]
for i in range (N):
    for j in range (N):
        if i < j :
             matrix[i][j] = 0

printMatrix (matrix)
