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