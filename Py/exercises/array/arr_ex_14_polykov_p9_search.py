#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
задание 14 глава массивы ст.72 учебник полякова 
напишите программу которая заполняет массив случаными трехзначиными числами
и находит в нем элемент с наибольшей суммой его цифр и его индекс

заметки по решению :
"""
from random import randint

#инициализация массива и заполение его случаными значениями
arrMax= 999
arrLength = 100
arr = [randint(100, arrMax) for i in range(arrLength)]
print (arr)
print("*" * 50)

#поиск в массиву
maxSum = 0
index = 0
i = 0
for i in range(arrLength):
    s = str (arr[i])
    firDig = int(s[0])
    secDig = int(s[1])
    thiDig = int(s[2])
    M = firDig + secDig + thiDig
    if M > maxSum : 
        maxSum = M
        index = i
print ("arr index is [{}] , summ is {}".format (index, maxSum))
print (   arr [index]  )

    