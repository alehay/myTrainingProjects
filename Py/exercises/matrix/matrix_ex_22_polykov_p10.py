"""
задание 22 глава матрицы ст.89 учебник полякова 

напишите программу, которая находит в матрицу максимальный элемент и удаляет строку и стоблец в которых он расположен



заметки по решению :
1) найти, обьект, и определить индексы пробежав массив (это сделали)
2) сгенерировать новый массив, копируя старый но пропустив индексы... хм 

как в боевике, найти и уничтожить. 
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

def find (matrix , N , M):
    i_max = -1
    j_max = -1
    num_max = -1

    for i in range (N):
        for j in range (M):
            if matrix [i][j] > num_max :
                num_max = matrix [i][j] 
                i_max = i
                j_max = j
    print ("max element")
    print (matrix [i_max][j_max])
    print ()
    return i_max,j_max

def destroy (matrix, kill_i , kill_j, N, M):
    new_matrix = [[0]*(M-1) for i in range(N-1)]
    new_i = 0    
    new_j = 0

    for i in range (N):
        if i != kill_i:
            for j in range(M):
                if j != kill_j:
                    new_matrix [new_i][new_j] = matrix [i][j]
                    new_j = new_j + 1
            new_j = 0
            new_i = new_i + 1        
        

    return new_matrix

N=7 #3 -ограничитель;  i  Y - индексы оси
M=4 #4 -ограничитель;  j  X - индекс оси. 

matrix_1 = [[0]*M for i in range(N)]

printMatrix (matrix_1)
printSeparator ("*", "matrix_1")

for i in range (N):
    for j in range(M):
        matrix_1 [i][j] = random.randint ( 2, 99)

printMatrix (matrix_1)
printSeparator ("*", "find")

x,y = find (matrix_1,N,M)

printSeparator ("*", "matrix_destroy")

new_matrix = destroy (matrix_1,x,y,N,M)
printMatrix (new_matrix)


#COMPLETE