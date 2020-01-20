#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Задание 15 глава массивы,стр.63 полякова 
напишите программу котоаря находи в массиве
все простые числа и строит из них новый массив. 
использутей логическую фукнцию isPrime которая возвращает истинное значение
если ей передано простое число . 
"""

"""
заметки по решению
"""
from random import randint

# провека числа принадлежность к ряду простых чисел 
def isPrime (n):
       if (n==1):
              return False
       elif (n==2): 
              return True # обработка иключейни
       else:
              for x in range (2,n):
                     if (n % x==0 ):
                            return False # если присутсвует делитель
              return True # если делителя нет









       
#инициализация массива и заполение его случаными значениями
arrLength = 100
arr = [randint(0, 500) for i in range(arrLength)]
print (arr)
print("*" * 50)

#создание массива с извлеченными простыми чсилами
primeArr = [x for x in arr if isPrime(x) ]
print (primeArr)