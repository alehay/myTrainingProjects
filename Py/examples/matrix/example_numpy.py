"""
примеры по турориалу в посте 
https://habr.com/ru/post/352678/
"""

import numpy 

#пример конвертации масива с ипользованием NuPy
A = numpy.array([[1, 2, 3], [4, 5, 6],[7,8,9],[10,11,12]], float)
print (A)
print (A[0,0])
print("*"*20)

"""
Array slicing работает с многомерными массивами аналогично,
 как и с одномерными, применяя каждый срез, как фильтр
 для установленного измерения. Используйте ":"
 в измерении для указывания использования всех элементов 
 этого измерения:
"""
print (" demo slicing :")
print (A[1,:])
print (A[:,1])

#метод shape взвращет количество строрк и столбцов:
print ("metod shape demo :")
print (A.shape)
print ("+"*20)

# Метод dtype возвращает тип переменных, хранщийся в массиве:
print ("method dtype demo:")
print (A.dtype)
print ("*"*20)

#len возвращает длинну первого измерения (оси):
print ("method len demo")
print (len(A))
print ("*"*20)

#метод in используется для проверки наличия элемента в массиве
print ( "method in demo")
print ( "number 5 is in the matrix ?" , 5 in A)
print ( "number 15 is in thw matrix ?,", 15 in A)

"""
Массивы можно переформировать при помощи метода, 
коотрый задет новый многомерный массив. 

ВНИМАНИЕ метод Reshape создает новый массив а не модицицируюет оригинальный
"""

B = numpy.array(range(10),float)
print ("Method Reshape demo ")
print  ("surce arr:")
print (B)
print ("reshape arr")
B = B.reshape((5,2))
print (B)
print ("shape is :" , B.shape)