"""
задание 24 глава матрицы ст.89 учебник полякова 

Напишите программу которая играет с человеком в крестики нолики на поле размером 3 на 3 



заметки по решению :
# мда прочитал про алгоритм МинМакс 


"""

"""
1) создать поле 3 на 3+
2) предложить выбор крестик или нолик +
3) присвоить игрокам соотвествующие символы
игровой цикл+ 

4) вывести поле (пустое)

цикл игры
    ход игрока
5)Попросить координаты для хода+
6)Осуществить ход , поствив фигуру в кординаты
7) Проверить ситуацию на поле 
    есть ли пустые ячейки? есть ли победа одного из игроков
8) принять решение по состоянию поля, продложить игру, победа, ничья

    ход машины
9) по алгоритму минимакс выбрать лутший ход. 
10) осущетсвить ход 
4) вывести поле
5) проверить состояние поля .
    есть ли пустые ячейки? есть ли победа одного из игроков
6) принять решение по состоянию полея, продолжить игру, победа , ничья  

"""
import sys
EMPTY = '_'
VERTICAL_COORDINATS = ('a', 'b', 'c')
AI_TURN = True
USER_TURN = False


def get_user_char():
    user_char = input('Select char (x, 0): ').strip(' ').lower() # strip - вырезает .lower -приводит к нижнему регистру
    while user_char not in ('x', '0'):
        print('Not available char')
        user_char = input('Select char (x, 0): ').strip(' ').lower()
    return user_char

def get_opponent_char(char):
    return '0' if char == 'x' else 'x'

def show_field(field):
    print(' ', '1', '2', '3')
    for y, v in enumerate(VERTICAL_COORDINATS):
        print(v, ' '.join(field[y]))

def get_user_position(field): # получение кординат от ползьвотеля
    real_x, real_y = 0, 0
    while True:
        coordinats = input('Input coordinats: ').lower().strip(' ')
        y, x = tuple(coordinats)

        if int(x) not in (1, 2, 3) or y not in VERTICAL_COORDINATS:
            print('Not valid coordinats')
            continue

        real_x, real_y = int(x) - 1, VERTICAL_COORDINATS.index(y)
        if field[real_y][real_x] == EMPTY:
            break
        else:
            print('Position not empty')

    return real_x, real_y

def is_draw(field):
    count = 0
    for y in range(3):
        count += 1 if EMPTY in field[y] else 0
    return count == 0 # вернуть true если все заполнено

def is_win(char, field):
    opponent_char = get_opponent_char(char)
    # проверяем строки
    for y in range(3):
        if opponent_char not in field[y] and EMPTY not in field[y]:
            return True

    # проверяем колонки
    for x in range(3):
        col = [field[0][x], field[1][x], field[2][x]]
        if opponent_char not in col and EMPTY not in col:
            return True

    # проверяем диагонали
    diagonal = [field[0][0], field[1][1], field[2][2]]
    if opponent_char not in diagonal and EMPTY not in diagonal:
        return True
    diagonal = [field[0][2], field[1][1], field[2][0]]
    if opponent_char not in diagonal and EMPTY not in diagonal:
        return True

    return False

def get_computer_position (field):# ход машины
    move = None
    best_score = -sys.maxsize
    board = [field[y].copy() for y in range(3)]
    for y in range(3):
        for x in range(3):
            if board[y][x] == EMPTY:
                board[y][x] = computer_char
                score = minimax(board, 0, USER_TURN)
                print ('comp_position')
                print('score is ', score, 'y is ', y , '  x is ', x)
                board[y][x] = EMPTY
                if score > best_score:
                    best_score = score
                    move = (x, y)

    return move

def minimax(board, depth, is_ai_turn): # основная фукцикция ради чего все писалос
    if is_win(computer_char, board):
        return scores[computer_char]
    if is_win(user_char, board):
        return scores[user_char]
    if is_draw(board):
        return scores['draw']

    if is_ai_turn:
        # выбираем ход который нам выгодней
        best_score = - 400 #-1000
        for y in range(3):
            for x in range(3):
                if board[y][x] == EMPTY:
                    board[y][x] = computer_char
                    score = minimax(board, depth + 1, USER_TURN)
                    board[y][x] = EMPTY
                    print ('min_max')
                    print('score is ', score, 'y is ', y , '  x is ', x)
                    print('bbest_score', best_score)
                    
                    best_score = max(best_score, score)
                    
    else:
        # противник выбирает ход который нам не выгоден
        best_score = 400 #+1000
        for y in range(3):
            for x in range(3):
                if board[y][x] == EMPTY:
                    board[y][x] = user_char
                    score = minimax(board, depth + 1, AI_TURN)
                    board[y][x] = EMPTY
                    best_score = min(best_score, score)
    return best_score

#создаем игровое поле 
field = [
    [EMPTY for x in range (3)] for y in range (3)
]

user_char = get_user_char() # выбрать символ
computer_char = get_opponent_char(user_char) # присвоить копьютеру альтернативный символ 

scores = {
    user_char: -100,
    computer_char: 100,
    'draw': 0
}

while True: # игровой цикл
    show_field (field)

    #ход человека
    x, y = get_user_position(field)
    field[y][x] = user_char

    # проверка на ничью
    if is_draw(field):
        print('is draw')
        show_field (field)
        break

    # проверка на победу!
    if is_win(user_char, field):
        print('you win')
        show_field (field)
        break
    
    # ход машины
    move = get_computer_position(field)
    if move is not None:
        x, y = move
        field[y][x] = computer_char
    
    # проверка на ничью
    if is_draw(field):
        print('is draw')
        show_field (field)
        break
    
    # проверка на победу машины
    if is_win(computer_char, field):
        print('you lose')
        show_field (field)
        break