"""
крестики-нолики 3х3
  1 2 3
a _ _ 0
b х _ 0
c х 0 _
Подготовительный этап
1.создать поле (_) 3 на 3, с координатами +
2.предложить выбрать крестик или нолик +
3. установить для компьютера крестик или нолик +
Игровой цикл
4 вывести поле с координатами +
5. Проверить ситуацию на поле +
6. Если ходить больше некуда, выводим сообщение "ничья" и выходим из игры +
7. Попросить координаты для хода +
8. поставить выбранную фигуру на поле по введенным координатам +
9. Проверить ситуацию на поле +
10. если собраны линии по вертикали,горирзонтали или по диагонали написать победа +
11. ход комьютера, координаты выбираются случайно из всего набора пустых ячеек +
12. Проверить ситуацию на поле +
13. если собраны линии по вертикали,горирзонтали или по диагонали написать "проиграл" +
"""
import sys
from random import randint

VERTICAL_COORDINATS = ('a', 'b', 'c')
EMPTY_CHAR = '_'
AI_TURN = True
USER_TURN = False


def get_user_char():
    user_char = input('Select char (x, 0): ').strip(' ').lower() # strip - вырезает .lower -приводит к нижнему регистру
    while user_char not in ('x', '0'):
        print('Not available char')
        user_char = input('Select char (x, 0): ').strip(' ').lower()
    return user_char


def show_field(field):
    print(' ', '1', '2', '3')
    for y, v in enumerate(VERTICAL_COORDINATS):
        print(v, ' '.join(field[y]))


def is_draw(field):
    count = 0
    for y in range(3):
        count += 1 if EMPTY_CHAR in field[y] else 0
    return count == 0


def get_user_position(field):
    real_x, real_y = 0, 0
    while True:
        coordinats = input('Input coordinats: ').lower().strip(' ')
        y, x = tuple(coordinats)

        if int(x) not in (1, 2, 3) or y not in VERTICAL_COORDINATS:
            print('Not valid coordinats')
            continue

        real_x, real_y = int(x) - 1, VERTICAL_COORDINATS.index(y)
        if field[real_y][real_x] == EMPTY_CHAR:
            break
        else:
            print('Position not empty')

    return real_x, real_y


def get_opponent_char(char):
    return '0' if char == 'x' else 'x'


def is_win(char, field):
    opponent_char = get_opponent_char(char)
    # проверяем строки
    for y in range(3):
        if opponent_char not in field[y] and EMPTY_CHAR not in field[y]:
            return True

    # проверяем колонки
    for x in range(3):
        col = [field[0][x], field[1][x], field[2][x]]
        if opponent_char not in col and EMPTY_CHAR not in col:
            return True

    # проверяем диагонали
    diagonal = [field[0][0], field[1][1], field[2][2]]
    if opponent_char not in diagonal and EMPTY_CHAR not in diagonal:
        return True
    diagonal = [field[0][2], field[1][1], field[2][0]]
    if opponent_char not in diagonal and EMPTY_CHAR not in diagonal:
        return True

    return False


def minimax(board, depth, is_ai_turn):
    if is_win(computer_char, board):
        return scores[computer_char]
    if is_win(user_char, board):
        return scores[user_char]
    if is_draw(board):
        return scores['draw']

    if is_ai_turn:
        # выбираем ход который нам выгодней
        best_score = - sys.maxsize
        for y in range(3):
            for x in range(3):
                if board[y][x] == EMPTY_CHAR:
                    board[y][x] = computer_char
                    score = minimax(board, depth + 1, USER_TURN)
                    board[y][x] = EMPTY_CHAR
                    best_score = max(best_score, score)
    else:
        # противник выбирает ход который нам не выгоден
        best_score = sys.maxsize
        for y in range(3):
            for x in range(3):
                if board[y][x] == EMPTY_CHAR:
                    board[y][x] = user_char
                    score = minimax(board, depth + 1, AI_TURN)
                    board[y][x] = EMPTY_CHAR
                    best_score = min(best_score, score)
    return best_score


def get_computer_position(field):
    move = None
    best_score = -sys.maxsize
    board = [field[y].copy() for y in range(3)]
    for y in range(3):
        for x in range(3):
            if board[y][x] == EMPTY_CHAR:
                board[y][x] = computer_char
                score = minimax(board, 0, USER_TURN)
                board[y][x] = EMPTY_CHAR
                if score > best_score:
                    best_score = score
                    move = (x, y)

    return move


field = [
    [EMPTY_CHAR for x in range(3)] for y in range(3)
]

user_char = get_user_char()
computer_char = get_opponent_char(user_char)

scores = {
    user_char: -100,
    computer_char: 100,
    'draw': 0
}

while True:
    show_field(field)
    if is_draw(field):
        print('is draw')
        break

    x, y = get_user_position(field)
    field[y][x] = user_char
    if is_win(user_char, field):
        print('you win')
        break

    move = get_computer_position(field)
    if move is not None:
        x, y = move
        field[y][x] = computer_char
        if is_win(computer_char, field):
            print('you lose')
            break

show_field(field)