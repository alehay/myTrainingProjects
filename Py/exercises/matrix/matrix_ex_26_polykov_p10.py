"""
задание 26 глава матрицы ст.89 учебник полякова 

В матрице, содержащец N строк и M столбцощв записана карта островного государства Лимония
(нули обозначают море. а единицы сушу) Все острова имеют форму прямугольника. 
Напишите программу которая по готовой карте определяет количество островов

заметки по решению :

    идея
    перебериаем массив, встречаем 1 ку. 
    так как массив переберается с лева н право с верху в низ
    записываем остров +1
    проверям "контур" острова, слева на право, с верху в низ
    индексты острова исключаем из проверки, проеряем дальше
    
    идея Самый простой и эфективный алгоритм выберу его
    подсмотрено с stackoverflow
    перебор по элементно, слева на право с верху вниз
    записываем остров +1
    идем дальше,
    слева и с верху есть земля? это продолжение острова. не считаем.

    альетрнатива с заливкой "водой" но суть такаяже. а нам надо меньше 
    действий

    идея 
    подсмотрено с stackoverflow 
    на поиск компонента связанности графа ... 
    где каждая точка будет соединена с 4 соседними . 
    метод рекурсвный , и всеравно достаточно тупой
    а как учит нас семья и школа: 
            " меожеш заменить рекурсию циклом заменяй"
            нет смысла излишняя сложность

сделаем генератор карты по условию 
"""
import random

N = 15
M = 15

def pythonStylePrintMatrix ( A ): 
    for row in A:
        for x in row:
            print ("{:4d}".format(x), end ="")
        print ()

def corner (D):
    run = True
    while run:
        run = False  
        for i in range (N):
            for j in range(M):
                if D[i][j] == 0:        
                    #case 1 top left corner
                    if i < N - 1 and j < M - 1:
                        if D[i + 1][j + 1] != 0 \
                        and D[i + 1][j] != 0 \
                        and D[i][j + 1] != 0:
                            D[i][j] = 1 
                            run = True
                    #case 2 top right corner 
                    if i < N - 1 and j > 0:
                        if D[i + 1][j - 1] != 0 \
                        and D[i + 1][j] != 0 \
                        and D[i][j - 1] != 0:
                            D[i][j] = 1
                            run = True                            
                    #case 3 bottom right corner 
                    if i>0 and j>0:
                        if D[i - 1][j - 1] != 0 \
                        and D[i - 1][j] != 0 \
                        and D[i][j - 1] != 0:
                            D[i][j] = 1                     
                            run = True
                    #case 4 bottom left corner
                    if i > 0 and j < M - 1:
                        if D[i - 1][j + 1] != 0 \
                        and D[i - 1][j] != 0 \
                        and D[i][j + 1] != 0:
                            D[i][j] = 1
                            run = True

def removeSmallIsland (D):
    run = True
    while run:
        run = False
        for i in range(N):
            for j in range(M):
                if D[i][j] == 1:
                    if i < N - 1 and j < M - 1 \
                        and i > 0 and j > 0:
                            if D[i + 1][j] == 0 \
                                and D[i-1][j] == 0 \
                                and D[i][j+1] == 0\
                                and D[i][j-1] == 0:
                                D[i][j] = 0
                                run = True
                    if i == 0 or j == 0\
                        or i == N-1 or j == M -1:
                        D[i][j] = 0

def getCountIslands (D):
    countIslands = 0
    for i in range(N):
            for j in range(M):
                if D[i][j] == 1 and D[i-1][j] == 0 and D[i][j-1] == 0:
                    countIslands = countIslands + 1
    return countIslands

for i in range (5):
    D = [[0]*M for i in range(N)]
    for i in range (N):
        for j in range(M):
            temp = random.gammavariate(0.1,1)
            if temp > 0.07:
                D [i][j] = 1
    
    
    removeSmallIsland (D)
    corner (D)
    pythonStylePrintMatrix (D)
    print ()
    print (getCountIslands (D))
    print ("*"*10)

#Complet!