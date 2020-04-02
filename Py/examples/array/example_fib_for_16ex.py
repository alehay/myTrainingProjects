#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 19 23:01:57 2020

@author: alehay
"""

"""
все коментарии сдесь это разбор задачи для понимания работы

данный код скопипячен из поста на хабре
https://habr.com/ru/post/261159/

генерирует ряд фибоначи. нужен тут для разбора
код длолжен быть справедлив для любой гомогенной 
последовательнсти идея в сипользование матрицы
{ фигурные скобки как индекс элемента}

  F{n}        1 1     F{n-1}
          =        *
 F{n-1}       1 0     F{n-2}


  1 1  ^n    F{n+1}    Fn
         =  
  1 0        Fn      Fn - 1
  
Два значения для x, полученных нами ранее, 
из которых одно представляло собою золотое сечение,
являются собственными значениями матрицы. 
Поэтому, ещё одним способом вывода замкнутой формулы является 
использование матричного уравнения и линейной алгебры.
  
       (A^(m/2))^2    для четных
A^m= 
       A * (A^((m-1)/2))^2
"""


def pow(x, n, I, mult):
    """
    Возвращает x в степени n. Предполагает, что I – это единичная матрица, которая 
    перемножается с mult, а n – положительное целое
    """
    if n == 0:
        return I
    elif n == 1:
        return x
    else:
        y = pow(x, n // 2, I, mult)
        y = mult(y, y)
        if n % 2:
            y = mult(x, y)
        return y


def identity_matrix(n):
    """Возвращает единичную матрицу n на n"""
    r = list(range(n))
    return [[1 if i == j else 0 for i in r] for j in r] # итератор заполения матрицы


def matrix_multiply(A, B):
    BT = list(zip(*B))
    return [[sum(a * b
                 for a, b in zip(row_a, col_b))
            for col_b in BT]
            for row_a in A]


def fib(n):
    F = pow([[1, 1], [1, 0]], n, identity_matrix(2), matrix_multiply)
    return F[0][1]

