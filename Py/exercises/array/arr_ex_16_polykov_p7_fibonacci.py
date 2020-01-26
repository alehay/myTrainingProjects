#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 19 19:24:38 2020

@author: alehay
"""

"""
задание 16 глава массивы ст.63 учебник полякова 
Напишите программу, которая находит в массиве все числа Фибоначи 
и стоит из них новый массив. Исопльзуте лочиескую фукнцию, которая 
возвращает истинное значение если переданноей число - число фибоначи.
"""

"""
заметки по решению 
*хорошая статья про фибоначи https://habr.com/ru/post/261159/

никаких способов кроме как сравнения с рядом я не нашел. 
вопспользуюсь хотябы тогда чужим хорошим генератором ряда...

поулчившееся решение, рабочее и связанное с копипастой чужой функици
с неполным пониманием ее работы.
"""

from random import randint
from example_fib_for_16ex import fib

# провека числа на принадлежность к ряду фибоначи
def isFib (n):
       if n == 0: return True
       i = 1
       
       while True:
              if n > fib(i): i = i + 1
              elif n == fib(i): 
                     return True
                     break
              else :
                     return False 
                     break
                       
#инициализация массива и заполение его случаными значениями
arrMax= 2990
arrLength = 1000
arr = [randint(0, arrMax) for i in range(arrLength)]
print (arr)
print("*" * 50)
#создание массива с извлеченными чсилами принадлежащими ряду фибначи
fibArr = [x for x in arr if isFib(x)]
print (fibArr)

# за одно найдем максимальный элемент
M = max (arr)
nMax = arr.index (M)
print ("arr [{}] = {}".format (nMax, M))