"""
задание 20-21 глава матрицы ст.88 учебник полякова 

заполните матрицу,  натуральными числами выполните траспонирование
тоесть транспонирование процедура в результте которой строки матрицы 
становятся столбцами а столбцы строками

пример                      

1   2   3             1   4   7 

4   5   6             2   5   8 

7   8   9             3   6   9 

а затем поверните матрицу обратно!


заметки по решению :
ну как бы все просто перезаполнить и баста
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

N=5 #3 -ограничитель;  i  Y - индексы оси
M=3 #4 -ограничитель;  j  X - индекс оси. 

matrix_1 = [[0]*M for i in range(N)]
printMatrix (matrix_1)
printSeparator ("*", "matrix_1")

num = 1
for i in range (N):
    for j in range (M):
        matrix_1 [i][j] = num
        num = num +1

printMatrix(matrix_1)
" транспонирование "
matrix_trans = [[0]*N for i in range(M)]  # создаем зеркальную пустую матрциу
for j in range (M):
    for i in range (N):
        matrix_trans [j][i] = matrix_1 [i][M-j-1]

printSeparator ("*", "matrix_trans")
printMatrix (matrix_trans)

matrix_trans2 = [[0]*N for i in range(M)]  # создаем зеркальную пустую матрциу
for j in range (M):
    for i in range (N):
        matrix_trans2 [j][i] = matrix_1 [N-i-1][j]
printSeparator ("*", "matrix_trans2")
printMatrix (matrix_trans2)

# COMPLETE!!!!