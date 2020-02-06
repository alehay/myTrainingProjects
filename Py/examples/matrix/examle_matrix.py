
"""
примеры и приемы работы с матрицамирасмотренные в учебнике полякова
"""
import random

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
D = [[0]*M for i in range(N)]
for i in range (N):
    for j in range(M):
        D [i][j] = random.randint ( 20, 80)
pythonStylePrintMatrix (D)
 
#перебор матрицы классический (сумма элементов)
summa = 0
for i in range (N):
    for j in range (M):
        summa += D [i][j]
print (summa) 

#перебор матрицы в стле Python (row переберает значения)
summa2 = 0
for row in D:
    summa2 +=sum ( row )

"""
квадратная матрица

  1    0    0  основаная           0    0    1   побочаня  

  0    1    0  диагональ           0    1    0   диагональ
   
  0    0    1                      1    0    0


перебор осной диагонали
for i in range (N):
    A [i][i]
перебор побочной
for i in range (N):
    A [i][N-1-i]
перебор под диагональю
for i in range(N):
    for j in range (i+1):
         A[i][j]
"""

#престаивить столбцы матрицы
for i in range(N):
    temp = D [i][2]
    D[i][2] = D[i][4]
    D[i][4] = temp

pythonStylePrintMatrix (D)
print( "_" *20)

#престаивить столбцы матрицы в стиле Pyton 
# множественное присваивание 
for i in range(N):
    D[i][1],D[i][3] = D[i][3],D[i][1]
pythonStylePrintMatrix (D)
print ("+"*20)

# Перестановка строк
# учитывая что A[i] это только ссылка на список элекментов строки [i]
# можно просто переставить ссылки 
D[0],D[2] = D[2],D[0]
pythonStylePrintMatrix (D)
print ("*"*20)
# нельзя получить копию строки с индексом [i] таким образом R = A [i]
# это будет является ссышка на существующую строку. 

#Копия получатся методом среза 
R = D [0][:] 
print (R)

# копия столбца с индексом j
# методом генератора

Z = [row[3] for row in D] 
print (Z)

#главная диагональ спомощью генератора

Y = [D[i][i] for i in range (N)]
print (Y)