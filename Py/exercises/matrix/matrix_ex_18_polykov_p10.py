"""
задание 18 глава матрицы ст.88 учебник полякова 

заполните матрицу, содержащую N строк и M столбцов натуральными числами 

вариант 1               вариант 2           вариант 3

1   2   3   4           4   3   2    1      6   5   4   3

2   3   4   5           5   4   3    2      5   4   3   2

3   4   5   6           6   5   4    3      4   3   2   1


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