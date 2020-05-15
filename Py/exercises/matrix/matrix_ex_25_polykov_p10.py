"""
задание 25 глава матрицы ст.89 учебник полякова 

Напришите программу которая обходит квадратную шахматную достку , заданного размера ходом коня. 
предварительно узнайте правило Вансдорфа 

заметки по решению :

жадный алгоритм - алгоритм ,который подразумевает локально оптимальное решение на каждом этапе,
допуская что общее конечное решение так же окажется оптимальным.

**** Основа решения правило Вансдорфа *** 
    Перед каждым ходом коня вычисляется рейтинг ближайших доступных полей - полей, 
    на которых конь еще не был, и на которые он может перейти за один ход.
    Рейтинг поля определяется числом ближайших доступных с него полей.
    Чем меньше рейтинг, тем он лучше. Потом делается ход на поле с наименьшим рейтингом 
    (на любое из таковых, если их несколько), и так далее, пока есть куда ходить.
"""

import copy

WHITE = '+'  
BLACK = '0'
OCCUPIED = 'X'
HORIZONTAL_CORDINATS = (
    'A','B','C','D','E','F','G','H',
     'I','J','K','L','M','N','O','P' 
     ) # x
VERTICAL_CORDINATS = (
        '1','2','3','4','5','6','7','8','9',
         '10','11','12','13','14','15','16'
        ) # y

def getCheckerBoardSize():
    sizeBoard = 0
    while True:
        sizeBoard = int(input('enter board size between 4 and 16: '))
        if sizeBoard >= 4 and sizeBoard <= 16:
            break 
    return sizeBoard

#  generate a board according to the given size
def getBoard(sizeBoard, firstСhar, secondСhar):
    board = [
            [firstСhar for y in range(sizeBoard)] for x in range(sizeBoard)
            ]
    #make the fields black and white
    for y in range(sizeBoard):
        for x in range(sizeBoard):
            if(y + x) % 2: 
                board [y][x]=secondСhar
    return board

def printBoard(A, horizontalCordinats, verticalCordinats):
    print('    ','   '.join(horizontalCordinats[0:len(A)]))
    for i in range(len(A)):
        print()
        print("{:2s}".format(verticalCordinats[i]),end="")
        for j in range(len(A[i])):
            print("  ", A[i][j], end="") 
        print() 

#get the coordinates from the user
def getPiece(board, horizontalCordinats , verticalCordinats):
    real_x, real_y = 0, 0
    while True:
        x = input('Input horizontal coordinats: ').upper().strip(' ')
        y = input('Input vertical coordinats:  ').upper().strip(' ')
        if (x) not in horizontalCordinats or (y) not in verticalCordinats:
            print('Not valid coordinats')
            continue
        real_x, real_y = horizontalCordinats.index(x), verticalCordinats.index(y)
        break
    return real_x, real_y

# busting chess horse moves 
def neighbor_xy(x, y):
    for dx, dy in (
            (-1, -2),#Noth   
            (1, -2),
            (2, -1),#est
            (2, 1),
            (1, 2), #soth
            (-1, 2),
            (-2, -1),#west
            (-2, 1)
    ):
        yield x + dx, y + dy


#move, 
def step(board, x, y): 
    bestScore = 5000
    buferBoard = copy.deepcopy(board)
    #check if the field is empty
    for neighbor_x, neighbor_y in neighbor_xy(x, y):
        if 0 <= neighbor_y < len(buferBoard[y]) \
        and 0 <= neighbor_x <  len(buferBoard[y])\
        and buferBoard[neighbor_y][neighbor_x] != OCCUPIED:                  
            buferBoard[neighbor_y][neighbor_x] = OCCUPIED 
            #we get the weight of this move
            score = getScore( buferBoard, neighbor_x, neighbor_y) 
            #remember the best move
            if score < bestScore:
                bestScore = score
                x,y = neighbor_x, neighbor_y 
            buferBoard[neighbor_y][neighbor_x] = board[y][x]
    return x,y
        
def getScore(board, x, y):  
    score = 0
    #if there are empty fields count them
    for neighbor_x, neighbor_y in neighbor_xy(x, y):
        if 0 <= neighbor_y < len(board[y]) \
        and 0 <= neighbor_x <  len(board)  \
        and board[neighbor_y][neighbor_x] != OCCUPIED :
            score = score + 1
    return score

#change the board according to the course
def resultBoard(board, x, y):
    board[y][x] = OCCUPIED
    return board

sizeBoard = getCheckerBoardSize()
board = getBoard(sizeBoard,WHITE,BLACK)
printBoard(board, HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)
x,y = getPiece(board, HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)
board = resultBoard(board, x, y)
iteration = 0
while (True) :
    board = resultBoard(board, x, y)
    printBoard(board, HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)
    x,y = step(board, x, y)
    print()
    print("итерация ", iteration)
    print("*" * 10)
    iteration = iteration + 1
    a = input("press k")