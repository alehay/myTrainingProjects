import numpy 
 
#булево срвнение может быть использоно для поэлементного сравнения массивов
# одинковых длин. Возращаемоге сзнание этих масивоу TRUE FALSA 


print ("Boolean comparison ")
a = numpy.array([[1,3,0],[4,6,5],[7,0,9]],float)
b = numpy.array([[1,3,4],[4,2,5],[9,8,9]],float)
print ("sourse array a")
print (a)
print()
print ("sourse array b")
print (b)
print()
print ("a==b")
print(a==b)
print()
print ("a<b")
print(a<b)
print()
print ("a>b = c")

#сохранение результов сравнения в массиве
c = a > b 
print(c)
print()

#сравнеие массивов с одиночным элументов

print ("sourse array a")
print (a)
print()
print ( "a>3" )
print (a>3)
print


#операты any и all могут быть исполязован для определения истины 
# одного или нескольких элементов соотвественно
print ("suorse array d")
d = numpy.array([[True,False,True],[False,True,False],[False,False,True]], bool)
print(d)
print()
print ("suorse array f")
f = numpy.array([False,True,False], bool)
print(f)
print()
#print ("any d:")
#print(any(d))
print()
print ("any F:")
print(any(f))
print()


#print ("all d:")
#print(all(d))
#print()
print ("all f:")
print(all(f))
print()

#комбинированные булевы выражения могут быть применены к масивам по
#принцупу элемент-эулемент  используя специальные функции logical_and, 
# logical_or, logical_not:



print(" surse array a")
print (a)
print ("logical_and(a>0, a<6)")
print ( numpy.logical_and(a>0, a<6))
print()
print("suorse massive")
print (f)
print ("logical_not f")
print ( numpy.logical_not(f))
print()
print("suorse massive d")
print (d)
print()
print ("logical_not d")
print ( numpy.logical_not(d))
print()

print ("sorse array")
print("suorse massive d")
print (d)
print ("suorse array f")
print (f)
print()
print ("logical_OR")
print (numpy.logical_or(d,f))
print()
print ("logical_XOR")
print (numpy.logical_xor(d,f))

print()
#функция Where создает новый массв из двух других масивов 
# одинаковых длин используется булев фильт для выброра 
# между двумя элементами. Базовый синтаксис where(bool_array,
# true_array, false_array):( условие : если True сделать : если Folse)

print ("sourse array a")
print (a)
print()
print ("numpy.where(a>3, a/3, a*a) :")
print (numpy.where(a>3, a/3, a*a))
print()

# некоторые функции дают возможность тестировать значения в масиве.
# Фукнция nonzero возвращыет кортеж индексов ненулевых знчений.
# Количество элементво в кортеже равно количеству осей в массиве.

print("demo nonzro func")
print("suorse array")
print (a)
print("non zero a")
print(a.nonzero())
print()

# проверка значение на коченость ,  иначе на NaN
h = numpy.array([1, numpy.NaN, numpy.Inf], float)
print ("sourse array h ")
print (h)
print()
print ("demo isanan function h")
print (numpy.isnan(h))
print()
print ("demo isfinite function h")
print (numpy.isnan(h))
print()

# мы можем использовать массив для фильтрации специфических 
# подмножеств элементов других массивов 

print("suorse array")
print (a)
print()
print ("array j = a>6 ")
j = a > 4 
print (j)
print()
print ("s array if a[j]")
s = a[j]
print (s)
print()

# блее сложная фильтрация требует булувых выраежний
print ("array numpy.logical_and (a > 3, a< 9)))")
print ( a[numpy.logical_and(a > 3, a < 9)])
print()

# Кроме булевого выбора можно использовать целочисленные массивы
# массив хранит индексы элементов, котоыре будут взяты из массива
"""
>>> a = np.array([2, 4, 6, 8], float)
>>> b = np.array([0, 0, 1, 3, 2, 1], int)
>>> a[b]
array([ 2.,  2.,  4.,  8.,  6.,  4.])
"""
#для многомерных массивов, необходимо предеать несколько одномерных 
# целочисленых масивов , (индексов) для каждой оси. 
# Потом каждый массив проходит последовательност первый илемент сооствесвует 
# индексу строки, который является первым элементов массива B 
# второй элемент соотвествует индкусу столбца который являеся жлементом масисива
# С и так далее. ( первый массив [2.2] и второй [1,4] имеем на выходе элементы 1,2 и 2.4) 
#
#
#
print("suorse array a")
print (a)
print()

b = numpy.array([0, 0, 2 ], int)
c = numpy.array([2, 2, 2 ], int)
print ( " array a[b,c] is: ")
print (a[b,c])
print()

# фукция take доступна для выполнения выборки 
# с целочисленными массивами. Это работает также как 
# и использования оператора взятия по индексу:

# представляет аргумент axis для взятия подсекции много мерного массива
# вдоль какой либо оси 

print("a.take(c,axis=1)")
print (a.take(c,axis=1))
print()
print("a.take(b,axis=1")
print (a.take(b,axis=1))
print()


# в противоположность к функции take есть функция put 
# которая будет брать значения из исходного массива и записывать их на специфические 
# индекс в другом put массиве
print ()
print(" demo put method")
aa = numpy.array([0,1,2,3,4,5],int)
bb = numpy.array([9,8,7],int)
print ("surce array a")
print (aa)
print ()
print ("source array b")
print (bb)
print ()
print()
print ("demo a.put[0,3], b")
c=numpy.array ([],int)
c = aa.put([0,3],bb)
print (c) 
# я хуй знает, но эта ебанина не работает как в примере
# надо будет с ней разобратся. Пока идем дальше


# Вектораня и матричаня математика

#  NumPy имеет встроенные фукнции для работы с векторами и матрицами

# функция dot возвращает скалярное произведение векторов

print ()
print(" demo DOT method")
a = numpy.array([1,2,3],float)
b = numpy.array([0,1,1],float)
print ("surce array a")
print (a)
print ()
print ("source array b")
print (b)
print ()
print ("numpu dot method")
print (numpy.dot(a,b))
print()


# функция dot так же может умножать матрицы:

a = numpy.array([[0,1],[2,3]],float)
b = numpy.array([2,3],float)
c = numpy.array([[1,1],[4,0]],float)
print ("surce array a")
print (a)
print ()
print ("surce array b")
print (b)
print ()
print ("surce array c")
print (c)
print ()
print ("numpy dot (b,a)")
print (numpy.dot(b,a))
print()
print ("numpy dot (a,b)")
print (numpy.dot(a,b))
print()
print ("numpy dot (a,c)")
print (numpy.dot(a,c))
print()
print ("numpy dot (c,a)")
print (numpy.dot(c,a))
print()

#Также можно получить скалярное,
#тензорное и внешнее произведение матриц и векторов.
#Заметим, что для векторов внутреннее и скалярное произведение
#совпадает. 
print (" demo outer ")
print()
a = numpy.array([1, 4, 0], float)
print ("souese array a")
print (a)
b = numpy.array([2, 2, 1], float)
print("sourse array b")
print(b)

print ("numpy outer (a,b)")
print (numpy.outer(a,b))
print()
print ("numpy inner (a,b)")
print (numpy.inner(a,b))
print()
print ("numpy cross (a,b)")
print (numpy.cross(a,b))
print()
print()

# numpy имеет набор встроенных функций и методов 
# для работы с линейной алгеброй
# это все можно найти в под модуле linalg
# этими модулями так же можно оперировать с вырожденными 
# и невырожденными матрциами .

# определитель матрицы ищится:

a = numpy.array([[4, 2, 0], [9, 3, 7], [1, 2, 1]], float)
print ("sourse array a (matrix) ")
print ()
print (a)
print ()
print ("numpu.linalg.det(a)")
print (numpy.linalg.det(a))
print()
# так же можно найти собственный вектор и 
# собственное значение матрицы 
print ("vals, vecs = numpy.linalg.eig(a)")
vals, vecs = numpy.linalg.eig(a)
print ("vals:")
print (vals)
print ("vecs:")
print (vecs)
print()

# поиск невырожденой матрицы
b = numpy.linalg.inv(a)
print()
print("b = numpy.linalg.inv(a)")
print(b)
print()
print("dot (a,b")
print (numpy.dot(a,b))

# одиночное разложение ( фнолог диагонализации не квадратной матрицы)
a = numpy.array([[1, 3,4], [5, 2, 3]], float)
U, s, Vh = numpy.linalg.svd(a)


print ("U")
print (U)
print("s")
print(s)
print("Vh")
print(Vh)