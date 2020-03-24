"""
задание 18 глава матрицы ст.88 учебник полякова 

заполните матрицу, содержащую N строк и M столбцов натуральными числами 

вариант 1               вариант 2           вариант 3

1   2   3   4           4   3   2    1      6   5   4   3

2   3   4   5           5   4   3    2      5   4   3   2

3   4   5   6           6   5   4    3      4   3   2   1


заметки по решению :
    
суть в заполнение от угла, надо подумать над алгоримтом . 

певый элемент индекс  [0,0]
вотопрой эелемент [1,0] и [0,1]
третий элемент [2,0] [0,2] и [1,1]

идея ? а что если использовать сумму индексов как определитель элемента?
(идея себя оправдала )
надо подогнать решенеи под другие случаи

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
        
N=9 #3
M=16 #4

matrix_1 = [[0]*M for i in range(N)]
printSeparator ("*","matrix1 ")

for i in range(N):
    for j in range(M):
        matrix_1 [i][j] = i+j+1 
printMatrix (matrix_1)

printSeparator ("*","matrix2")

matrix_2 = [[0]*M for i in range(N)]
for i in range(N):
    for j in range(M):
        matrix_2 [i][j] = i+(M-j)

printMatrix (matrix_2)

printSeparator ("*","matrix3")


matrix_3 = [[0]*M for i in range(N)]
for i in range(N):
    for j in range(M):
        matrix_3 [i][j] = (N-i)+(M-j)-1

printMatrix (matrix_3)

#COMPLETE!