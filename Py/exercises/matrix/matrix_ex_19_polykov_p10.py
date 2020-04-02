"""
задание 19 глава матрицы ст.88 учебник полякова 

заполните матрицу, содержащую N строк и M столбцов натуральными числами
по спирали змейкой ПРИМЕРЫ 

вариант 1               вариант 2           вариант 3

1   2   3   4           1   3   4    9       1   6   7   12

10  11  12  5           2   5   8    10      2   5   8   11

9   8   7   6           6   7   11   12      3   4   9   10


заметки по решению :


основа релеша, алгоритм я вприципе создал алгоритм тупой. и не очень то крсивый.
и сложный достаточно, в нем ошибка . но несложная но надо будет вернутся и решить

!!!!!!!!!!!!!!!!!!!!!!!!1
РЕШЕНИЕ С ОШИБКОЙ Я ПЕРЕПУТАЛ ИНДЕКСЫ МАССИВОВ И НАПРАВЛЕНИЕ ОСЕЙ. 
АЛГОРИТМ РАБОЧИЙ НО РЕАЛИЗАЦИЯ ПЕРЕПУТАННАЯ
в решении 20 задания, правильная ассоциая осей. 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
        
# будем предпологать, что фиукнция уже подразумеват тип спирального хода. 
# но спираль, поворачивает , значит  вопрос, нужно ли мне иметь информацию 
# о том, на краю ли я, и уперся ли в уже заполненую ячейку. 


def getDirection (matrix,x,y,N,M, initial_direction ): 
    
    if initial_direction == 1 :  # идя на север,
        if y > 0 and matrix[x][y-1] == 0:  # не уперевшись в рамку, и в заполненый элемент
            direction = 1                  # продолжаем двигаься в этом направлении
        elif y == 0 or matrix[x][y-1] != 0: # если рамка или заполнено, поворачиваем на право ( на восток)
            direction = 2 # НЕТ на запад
        else:
            direction = 0                  # отбивка если что то не так. 
        return direction

    if initial_direction == 2: # Это юг получается ну хз
        if x < N - 1 and matrix [x+1][y] == 0:
            direction = 2
        elif x == N-1 or matrix [x+1][y] !=0:
            direction = 3 
        else:
            direction = 0
        return direction

    if initial_direction == 3: # восток.
        if y < M-1 and matrix [x][y+1] ==0:
            direction = 3
        elif y == M - 1 or matrix [x][y+1] != 0:
            direction = 4
        else:
            direction = 0
        return direction

    if initial_direction == 4: # идем на запад
        if  x > 0 and matrix [x-1][y] == 0:
            direction = 4
        elif x == 0 or matrix [x-1][y] != 0:
            direction = 1
        else:
            direction = 0
        return direction


# изменить кординату по наравлению 
def getСhangedСoordinates ( x, y, direction ) :
    if direction == 1: #идем на север
        y = y-1 
    if direction == 2: #идем на восток
        x = x+1
    if direction == 3: #идем на юг
        y = y+1
    if direction == 4: #идем на запад
        x = x-1
    return  (x,y)



N=5 #3 -ограничитель;  i  X - индексы оси
M=3 #4 -ограничитель;  j  Y - индекс оси. 

direction = 0 # 0 - нет направления, 1 - север, 2 восток , 3 юг, 4 запад.  

matrix_1 = [[0]*N for i in range(M)]

printMatrix (matrix_1)
printSeparator ("*", "matrix_1")
 
i = 0  # стартовые условия.  
j = 0
num = 1
direction = 1

for z in range (N*M):
    matrix_1[i][j] = num    
    num = num+1
    direction = getDirection(matrix_1, i,j,N,M,direction)
    i, j = getСhangedСoordinates (i,j,direction )

printMatrix (matrix_1)

