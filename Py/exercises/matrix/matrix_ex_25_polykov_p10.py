"""
задание 25 глава матрицы ст.89 учебник полякова 

Напришите программу которая обходит квадратную шахматную достку , заданного размера ходом коня. 
предварительно узнайте правило Вансдорфа 

заметки по решению :
в прошлой задаче номер 24, крестики "нулики" был иследован, алгорит минимакс и сейчас он мне понадобится. 
ибо правило Варнсдорфа , частный случай жадного алгоритма, на примере обхода конем шахматной доски, 
предполагает вычислие рейтинга ячеек на которые может сходить конь. 

жадный алгоритм - алгоритм ,который подразумевает локально оптимальное решение на каждом этапе,
допуская что общее конечное решение так же окажется оптимальным.

    противоположность. 
    Динамическое программирование  — способ решения сложных задач путём разбиения их на более простые подзадачи. 
    Он применим к задачам с оптимальной подструктурой, выглядящим как набор перекрывающихся подзадач,
    сложность которых чуть меньше исходной. 

Перед каждым ходом коня вычисляется рейтинг ближайших доступных полей - полей, 
на которых конь еще не был, и на которые он может перейти за один ход.
Рейтинг поля определяется числом ближайших доступных с него полей.
Чем меньше рейтинг, тем он лучше. Потом делается ход на поле с наименьшим рейтингом 
(на любое из таковых, если их несколько), и так далее, пока есть куда ходить.

"""

"""
1) получить размер доски +
2) сгенерировать доску +
и вывести ее . +
    чернобелую? крайнее левое верхнее поле всегда белое, тоесть первый элемет +
3) возожно даже с нотацией. ( ленивая я жопа в прошлой задаче был же пример) (чет мне лень рисовать доску в правильную сторону)
4) получить изначальную позицию лошади, 

  вопрос, попробовать указать глубину. просчета ???

цикл хода коня.  

5) алгоримт принятия решения, о ходе, 

6) вывод доски 

    вопрос , попробовать  дать возможность вывода через несколько итераций. 

осуществить ход , и вывести доску. с ходом. 

"""

WHITE = '*'
BLACK = '+'
HORIZONTAL_CORDINATS = ('A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' )
VERTICAL_CORDINATS = ('1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16')

def getCheckerBoardSize ():
    sizeBoard = 0
    while True:
        sizeBoard = int(input('enter board size between 4 and 16: '))
        if sizeBoard >= 4 and sizeBoard <= 16:
            break 
    return sizeBoard

def getBoard (sizeBoard, firstСhar , secondСhar):
    board = [
        [firstСhar for x in range(sizeBoard)] for y in range(sizeBoard)
    ]
    for y in range (sizeBoard):
        for x in range (sizeBoard):
            if (y+x)%2 :
                board [y][x] = secondСhar
    return board

def printBoard ( A , horizontalCordinats , verticalCordinats):
    print ('    ','   '.join(horizontalCordinats[0:len(A)]))
    for i in range(len(A)):
        print ()
        print("{:2s}".format (verticalCordinats[i]),end="")
        for j in range(len(A[i])):
            print ("  ", A[i][j], end="")  #, end ="  "
        print() #для перевода на новую строку. 

def getPiece(board):
    real_x, real_y = 0, 0
    while True:
        coordinats = input('Input coordinats: ').lower().strip(' ')
        y, x = tuple(coordinats)
        """
        if int(x) not in (range) or y not in VERTICAL_COORDINATS:
            print('Not valid coordinats')
            continue
        real_x, real_y = int(x) - 1, VERTICAL_COORDINATS.index(y)
        if field[real_y][real_x] == EMPTY:
            break
        else:
            print('Position not empty')
        """
    return real_x, real_y

sizeBoard = getCheckerBoardSize()

print (sizeBoard)

board = getBoard(sizeBoard,WHITE,BLACK)

printBoard(board,HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)

getPiece(board)