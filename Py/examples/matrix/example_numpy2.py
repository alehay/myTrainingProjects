import numpy 

#функция arange аналогична функции range, но возвращает масисв:
#start . stop. step
A = numpy.arange(0,50,5, dtype=float)
print ("arange demo")
print (A)
print ("+"*20)
print()

#Функция zeros and ones сздают новые массивы с установленной размерностью,
#заполненные этими значениями.
# Самоя простая функция использования массивов
B = numpy.ones((4,5), dtype=float)
print ("Ones function demo ")
print (B)
print()
C = numpy.zeros (10, dtype=int) 
print ("zeros function demo ")
print (C)
print ("+"*20)
print()

#функция zeros_like и ones_like
#могут преобзразовать уе созданный масив 
#заполняя нулями и единицами
D = numpy.array([[1,2,3],[4,5,6]],float)
print ("zeros_like and ones_like function demo ")
print ("suource array")
print (D)
print()
print ("zeros_like:")
D = numpy.zeros_like(D)
print (D)
print()

print ("ones_like:")
D = numpy.ones_like(D)
print (D)
print ("+"*20)
print()

# Функции для создания специальныйх матриц
# создание квардатной матрицы с главной диагональню 
# которая заполнена единицами метод Identity:

E = numpy.identity(6, dtype = float)
print ("indentity demo")
print (E)
print()

# функция eye возвращает матрицу с единицами на диагонали k 
print ("eye function demo")
G = numpy.eye (4, k=2, dtype=float)
print (G)
print ("+"*20)
print()

"""
математичесие операции над массивами. 

должен соблюдатся прицип : элемент--элемент. 
массивы должны быть одинакового размера во 
время подобных операций
"""
# ВНИМАНЕ умножение производится поэлементно и несоотвесвтует умножению матриц

print ("mathematical operation matrix")
F = numpy.array([[1,2,3],[4,5,6],[0,5,7]], float)
J = numpy.array([[8,9,10],[11,12,13],[13,-4,7]], float )
print ("source matrix F")
print(F)
print()
print ("surce matrin J")
print(J)
print()

print ("F + J :")
print (F+J)
print()

print ("F - J :")
print (F-J)
print()

print ("F * J :")
print (F*J)
print()

print ("F / J :")
print (F/J)
print()

print ("F % J :")
print (F%J)
print()

print ("F ** J :")
print (F**J)
print()
print("/"*20)
print()

# ВНИМАНЕ умножение производится поэлементно и несоотвесвтует умножению матриц

# Если размерность массивов не совпадает они будут преобзованы для выполенния
# Это оозначает что меньший массив будет использоват НЕСКОЛЬКО раз для завершения 
# операций. 

print ("source matrix F")
print(F)
print()

K = numpy.array ([-1,3,4],float)
print ("source matrix K")
print(K)
print()

print ("F + K")
L = F + K
print(L)
print()
print("*"*30)


# когда важнj контролиролвать преобзования исполльзуется 
# константа nweaxis
print ("newaxis F + K")

print ("source matrix F")
print(F)
print()
print ("source matrix K")
print(K)
print()
L = F + K[numpy.newaxis,:]
print ("L = F + K[numpy.newaxis,:]")
print (L)
print()
print("*"*30)
L = F + K[:,numpy.newaxis]
print ("L = F + K[:,numpy.newaxis]")
print (L)
print()
print("*"*30)

# в numpy включена библиотека сандартныйх 
# матеатических функций которые могут быть применены 
# поэлементно кмасиивам
# abs, sign, sqrt, log, log10, exp, sin, cos, tan, arcsin, 
# arccos, arctan, sinh, cosh, tanh, arcsinh, arccosh, и arctanh.

print ( "sqrt demo "  )
print ("source matrix F")
print(F)
L = numpy.sqrt(F)
print ("after sqrt")
print(L)
print()
print("*"*30)


# функции Floor , ceil и rint возвращают нижнее , 
# верхнее или ближайщее значение (округление)

print ("source matrix F")
print(F)
print()
print ("source matrix L")
print(L)
print()


print ("Floor matrix F")
print(numpy.floor(F))
print()
print ("Floor matrix L")
print(numpy.floor(L))
print()

print ("ceil matrix F")
print(numpy.ceil(F))
print()
print ("ceil matrix L")
print(numpy.ceil(L))
print()

print ("rint matrix F")
print(numpy.rint(F))
print()
print ("rint ceil L")
print(numpy.rint(L))
print()

# перебор элементов массива 

# итерация массивов аналогично спискам.

a =  numpy.array([2,5,7,12], int)
for x in a:
    print (x)
print()

b = numpy.array ([[1,2,3],[6,2,7],[9,1,2]],float)
print ("suourse array")
print (b)
print ("array enumeration: ")
for x in b:
    print (x)
print()

print ("array asiignment: x*y-z ")
for (x, y, z) in b:
    print (x*y-z)
print()

# базовые операци над массивами
print ("summ massive")
print ("suourse array")
print (b)
print()
print("summ masive numPy:")
print (numpy.sum(b))
print()
print("prod masive base:")
print (numpy.prod(b))
print()

# функции которые доют возможность оперирровать 
# к статистическим данным. 
# фукнция Mean ( среднее арифматическиое)


print ("suourse array")
print (b)
print()
print("masive mean :")
print (b.mean())
print()
print("masive mean axis =1 :")
print (b.mean(axis=1))
print()

print("masive var - variation:")
print (b.var())
print()

print("masive var  axis = 0- variation:")
print (b.var(axis=0))
print()

print("masive std :")
print (b.std())
print()

print("masive std axis =1 :")
print (b.std(axis=1))
print()


print("masive max :")
print (b.max())
print()

print("masive max axis = 1 :")
print (b.max(axis=1))
print()


print("masive min :")
print (b.min())
print()

print("masive min axis =1  :")
print (b.min(axis=1))
print()

print("masive argmin :")
print (b.argmin())
print()

print("masive argmin axis=0:")
print (b.argmin(axis=0))
print()

print("masive argmax :")
print (b.argmax())
print()

for i in range (3):
    print("*"*25)
print()

#сокращение значений в массиве . 
# что принадлежать к заданному диапазаону.
# .то тоже самое что примеять 
# min(max(x, minval), maxval) к каждому элементу
print("Clip method demo")
a = numpy.array([6, 2, 5, -1, 0], float)
print ("sourse matrix")
print (a)
print ("clip matrix clip(1, 5)")
print (a.clip(1, 5))
print()

# извлучение уникальных элекментов
a = numpy.array([1, 1, 4, 5, 5, 5, 7], float)
print("unique method")
print ("sourse matrix")
print (a)
print ("unique method")
print (numpy.unique (a))
print()

# получение диагонали квадратной матрицы
print ("sourse matrix")
print (b)
print ("diagonal method")
print (b.diagonal())
print()
print ("diagonal method axis1")
print (b.diagonal(axis2=1))

print()

# дополнительные методы для работы со статистическими даныыми в массивах 

#медина может быть найдена

print (" demo median method ")
a1 = numpy.array([1,4,3,8,9,2,3], float)
print("suorse array is :")
print (a)
print ("numpy median is")
print (numpy.median(a1))
print()

# коэффициент корреляции для некоторых переменных 
# наблюдается несколько раз и может быть найден
# массивов вида 
# [[x1,x2,...],[y1,y2,...],[z1,z2,...]]
# где x,y,z  это рзаные квантовые наблюдаемые и
# и нометра указывают количество "наблюдейний"
print()
print ("corrcoef method" )

a = numpy.array([[1,2,1,3],[5,3,1,8]], float)
print ("suorse array is")
print (a)

c = numpy.corrcoef(a)
print ("numpy.corrcoef(a)")
print (c)

print()

# Имеем возрващаемый массив  с [i, j ] который хранит коэффицент 
# для i - тых и j тыъ кватовых наблюдаемых 

# аналогично ковариационный момент может быть найдет 

print ("numpy cov method")
print   (numpy.cov(a))
print()
#nympy рандом 
print("print random seed")
x = numpy.random.rand(5)
print (x)
print()

print ("random array")
print (numpy.random.rand(2,3))
print()
print ("random randint")
z = numpy.random.randint(5,10)
print (z)