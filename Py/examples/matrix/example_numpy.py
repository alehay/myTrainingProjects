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
print ("+"*20)

"""
#метод Copy используется для создания копии существующего 
массива в памяти 
"""
C = A.copy()

#создание список из массва. 
D = numpy.array([1,2,3,4,5,6], float)
print ("demo matrix to list")
print ("array D ")
print (D)
print ("list D")
D.tolist()
print ("to list B", D)
print (list(D))
print ("+"*20)

"""
можно переконвертировать массив в бинарную строку ( non human-readable)
Используйте метот tostrin. Метот Fromstrin рабртает для обратного 
преобразования. Эти операции полезны для сохранения большого количества данных в файлах
которые могут быть считаны
"""
print ("tostrin and from string demo")
print ("suorse matrix D",D)
S = D.tostring()
print ("tostring matrix: ",S)
E = numpy.fromstring(S)
print ("fromstring S",E)
print ("+"*20)

# заполаненеи масисва одинаковым занчением  метод fill
print ("Method fill demo")
print ("suorse arr D:", D)
D.fill(0)
print ("D arr after fill:",D)
print ("&"*23)

# транспонирование массива
print ("suorce matrix A")
print (A)
print()
E = A.transpose()
print ("transpose A")
print()
print (E)
print()
print("/"*30)

#конвертация массива в одномерный метод Flatten
print()
print ("source matrix is ", A)
print()
print ("arr after fletten metod")
F = A.flatten()
print ()
print (F)
print ()
print ("#"*30)

# конкатенация массивов методо Concatenate

a = numpy.array ([[1,2,3],[4,5,6]], float)
b = numpy.array ([[7,8,9],[10,11,12]], float)
c = numpy.array ([[13,14,15],[16,17,18]], float)
d = numpy.concatenate((a,b,c))

print ()
print ("demo concatenate method")
print (d)
print ()
print ("*"*20)
# конкатенация массивов методо Concatenate 
# задание оси конкатенации
d = numpy.concatenate((a,b,c), axis=0)
print ()
print ("demo concatenate method AXIS 0")
print (d)

d = numpy.concatenate((a,b,c),axis=1)
print ()
print ("demo concatenate method AXIS 1")
print (d)
print ()
print ("*"*20)
# размерность массива может быть увеличена при использовании константы
# newaxis в квадратных скобках. 
x = numpy.array([88,99,77],float)
y = x[:,numpy.newaxis]
z = x[numpy.newaxis,:]
print ("newaxis demo")
print ("source array a ")
print (x)
print()

print ("y array after newaxis ")
print (y)
print ()
print ("z array after newaxis")
print (z)
print ()
print ("shape x ")
print(x.shape)
print ()
print ("shape y ")
print(y.shape)
print ("shape z ")
print(z.shape)

print (" concatinete a and z")
e = numpy.concatenate((a,z))
print (e)
print ("concatinete z and a axis = 0")
l = numpy.concatenate((z,a),axis=0)

print (l)
print ()
# тут каждый массив двумерный. созданный при помощи newsxis имеет размерность один.
# подходит для удобного создания мерных массивов в векторной и матричной алгебре.  