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
4) получить изначальную позицию лошади,  +
  
       
  вопрос, попробовать указать глубину. просчета ???     ГЛУБИНУ ВО ВТОРОЙ ИТАРАЦИИ БУДУ ПИСАТЬ
цикл хода коня. 

изменение позици в соотвествии с ходом  +
 
5) алгоримт принятия решения, о ходе, 
        1) определить , куда можно сходить ?  в идеальном варианте должно быть 8 ходов
        2) если некуда ходить, вернуть то что ходить некуда, конец программы
        3) вычислить наиболее выгодный ход? (как ? ) 
                (делаем условный ход, в выбраном направлении и смотрим сколько ячеек доступно  ) глубина 1
                    (делаем условны ход , вы выбраном направлении .......................................) глубина 2
                        ......
        возвращаем "вес" 
        делаем ход с наибольшим весом. 
        
    
6) вывод доски 
   вопрос , попробовать  дать возможность вывода через несколько итераций. 

осуществить ход , и вывести доску. с ходом. 

"""
import copy

WHITE = '0' 
BLACK = '0'
OCCUPIED = 'X'
HORIZONTAL_CORDINATS = ('A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' ) # x
VERTICAL_CORDINATS = ('1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16') #y

# получаем размер доски
def getCheckerBoardSize ():
    sizeBoard = 0
    while True:
        sizeBoard = int(input('enter board size between 4 and 16: '))
        if sizeBoard >= 4 and sizeBoard <= 16:
            break 
    return sizeBoard

# генерируем доску
def getBoard (sizeBoard, firstСhar , secondСhar):
    board = [
        [firstСhar for y in range(sizeBoard)] for x in range(sizeBoard)
    ]
    
   
    #делаем поля чернобелыми
    for y in range (sizeBoard):
        for x in range (sizeBoard):
            if (y+x)%2 : 
                board [y][x] = secondСhar
   
    return board

# вывод доски 
def printBoard ( A , horizontalCordinats , verticalCordinats, ):
    print ('    ','   '.join(horizontalCordinats[0:len(A)]))
    for i in range(len(A)):
        print ()
        print("{:2s}".format (verticalCordinats[i]),end="")
        for j in range(len(A[i])):
            print ("  ", A[i][j], end="")  #, end ="  "
        print() #для перевода на новую строку. 

#получение кординат от пользователя 
def getPiece(board, horizontalCordinats , verticalCordinats):
    #horizontal - x vertical - y
    real_x, real_y = 0, 0
    while True:
        x = input('Input horizontal coordinats: ').upper().strip(' ')
        y = input('Input vertical coordinats:  ').upper().strip(' ')
        if (x) not in horizontalCordinats or (y) not in verticalCordinats:
            print('Not valid coordinats')
            continue
        real_x, real_y = horizontalCordinats.index(x) , verticalCordinats.index(y)
        break
                
    return real_x, real_y


# диференциал для хода шахматного коня 
def neighbor_xy(x, y):
    for dx, dy in (
            (-1, -2), #Noth   
            (1, -2),
            (2, -1), #est
            (2, 1),
            (1, 2), #soth
            (-1, 2),
            (-2, -1), #west
            (-2, 1)
    ):
        yield x + dx, y + dy


#расчет кординат хода  хода, 
def step(board, x,y,depth):
       
    
    buferBoard = copy.deepcopy(board)
    bestScore = -1
    score = -2
    # если поле не пройдено и не за границей доски 
    for neighbor_x, neighbor_y in neighbor_xy(x, y):
        print ("debag messege: ")
        print ("neighbor_x", neighbor_x )
        print ("neighbor_y", neighbor_y )
        if 0 <= neighbor_y < len(buferBoard[y]) \
        and 0 <= neighbor_x <  len(buferBoard)  \
        and buferBoard[neighbor_y][neighbor_x] != OCCUPIED :
            print ("debag messege: ")
            print ("")
            
            x = neighbor_x
            y = neighbor_y 
            buferBoard[y][x] = OCCUPIED # cовершаем ход
            score = getScore (buferBoard,score,x,y,depth-1) # считаем вес при данном ходе
            
            buferBoard[y][x] = board [y][x] # возвращаем состояние 
            if score > bestScore: # если вес лутший запоминаем
                bestScore = score
                
                print("best score is ", bestScore)             
                return x,y

        #проверить , куда можно идти .
        #если есть пустые клетки добавть к score +1
        #после итерации прибавить  глубину



# рекусивно высчитываем вес по зданной глубине , для позиции    
def getScore (buferBoard,score,x,y,depth):  
    #получаем ход куда хотим сходить 
    #проверяем соседние клетки
   
    for neighbor_x, neighbor_y in neighbor_xy(x, y):
        if 0 <= neighbor_y < len(buferBoard[y]) \
        and 0 <= neighbor_x <  len(buferBoard) \
        and buferBoard[neighbor_y][neighbor_x] != OCCUPIED :
            if depth == 0:               
                
                return  score + 1
            else:
                buferBoard[neighbor_y][neighbor_x] = OCCUPIED
                score = getScore(buferBoard,score,neighbor_x,neighbor_y,depth-1)
        else:
            return score



#изменениенение доски в соотвествии с полученным ходом 
def resultBoard(board,x,y):
    board[y][x] = OCCUPIED
    return board

#начало программы
# получили размер 
sizeBoard = getCheckerBoardSize()
# сгенерировали доску по заданным параметрам
board = getBoard(sizeBoard,WHITE,BLACK)

#вывели доску и кординаты
printBoard(board,HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)

#спросили стартовую позицию 
x,y = getPiece(board,HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)

board = resultBoard(board, x,y)

printBoard(board,HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)



for i in range (100):

    board = resultBoard(board, x,y)

    printBoard(board,HORIZONTAL_CORDINATS, VERTICAL_CORDINATS)

    x,y = step (board, x,y, 2)
    print()
    print()
    print("*"*10)
    a = input("press k")