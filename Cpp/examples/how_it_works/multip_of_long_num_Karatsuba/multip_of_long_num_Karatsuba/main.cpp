#include <cstring>

#define BASE 10 //система счисления
#define MIN_LENGTH_FOR_KARATSUBA 4 //числа короче умножаются квадратичным алгоритмом
typedef int digit; //взят только для разрядов числа
typedef unsigned long int size_length; //тип для длинны числа

using namespace std;

struct long_value { //тип для длинных чисел
  digit *values; //массив с цифрами числа записанными в обратном порядке
  size_length length; //длинна числа
};

long_value sum(long_value a, long_value b) {
  /* функция для суммирования двух длинных чисел. Если суммируются числа разной длинны
  * то более длинное передется в качестве первого аргумента. Возвращает новое
  * ненормализованное число.
  */
  long_value s;
  s.length = a.length + 1;
  s.values = new digit[s.length];

  s.values[a.length - 1] = a.values[a.length - 1];
  s.values[a.length] = 0;
  for (size_length i = 0; i < b.length; ++i)
    s.values[i] = a.values[i] + b.values[i];
  return s;
}

long_value &sub(long_value &a, long_value b) {
  /*функция для вычитания одного длинного числа из другого. Изменяет содержимое первого
  * числа. Возвращает ссылку на первое число. Результат не нормализован.
  */
  for (size_length i = 0; i < b.length; ++i)
    a.values[i] -= b.values[i];
  return a;
}

void normalize(long_value l) {
  /*Нормализация числа - приведение каждого разряда в соответствие с системой счисления.
  *
  */
  for (size_length i = 0; i < l.length - 1; ++i) {
    if (l.values[i] >= BASE) { //если число больше максимального, то организовавается перенос
      digit carryover = l.values[i] / BASE;
      l.values[i + 1] += carryover;
      l.values[i] -= carryover * BASE;
    } else if (l.values[i] < 0) { //если меньше - заем
      digit carryover = (l.values[i] + 1) / BASE - 1;
      l.values[i + 1] += carryover;
      l.values[i] -= carryover * BASE;
    }
  }
}

long_value karatsuba(long_value a, long_value b) {
  long_value product; //результирующее произведение
  product.length = a.length + b.length;
  product.values = new digit[product.length];

  if (a.length < MIN_LENGTH_FOR_KARATSUBA) { //если число короче то применять наивное умножение
    memset(product.values, 0, sizeof(digit) * product.length);
    for (size_length i = 0; i < a.length; ++i)
      for (size_length j = 0; j < b.length; ++j) {
        product.values[i + j] += a.values[i] * b.values[j];
        /*В случае изменения MIN_LENGTH_FOR_KARATSUBA или BASE расскоментировать следующие
        * строки и подобрать соотв. значения для исключения переполнения разрядов.
        * Например для десятичной системы счисления число 100, означает, что организовавается
        * перенос 1 через один разряд, 200 - перенос 2 через один разрряд, 5000 - 5 через два.
        * if (product.values[i + j] >= 100){
        *   product.values[i + j] -= 100;
        *   product.values[i + j + 2] += 1;
        * }
        */
      }
  } else { //умножение методом Карацубы
    long_value a_part1; //младшая часть числа a
    a_part1.values = a.values;
    a_part1.length = (a.length + 1) / 2;

    long_value a_part2; //старшая часть числа a
    a_part2.values = a.values + a_part1.length;
    a_part2.length = a.length / 2;

    long_value b_part1; //младшая часть числа b
    b_part1.values = b.values;
    b_part1.length = (b.length + 1) / 2;

    long_value b_part2; //старшая часть числа b
    b_part2.values = b.values + b_part1.length;
    b_part2.length = b.length / 2;

    long_value sum_of_a_parts = sum(a_part1, a_part2); //cумма частей числа a
    normalize(sum_of_a_parts);
    long_value sum_of_b_parts = sum(b_part1, b_part2); //cумма частей числа b
    normalize(sum_of_b_parts);
    long_value product_of_sums_of_parts = karatsuba(sum_of_a_parts, sum_of_b_parts);
    // произведение сумм частей

    long_value product_of_first_parts = karatsuba(a_part1, b_part1); //младший член
    long_value product_of_second_parts = karatsuba(a_part2, b_part2); //старший член
    long_value sum_of_middle_terms = sub(sub(product_of_sums_of_parts, product_of_first_parts), product_of_second_parts);
    //нахождение суммы средних членов

    /*
    * Суммирование многочлена
    */
    memcpy(product.values, product_of_first_parts.values,
      product_of_first_parts.length * sizeof(digit));
    memcpy(product.values + product_of_first_parts.length,
      product_of_second_parts.values, product_of_second_parts.length
      * sizeof(digit));
    for (size_length i = 0; i < sum_of_middle_terms.length; ++i)
      product.values[a_part1.length + i] += sum_of_middle_terms.values[i];

    /*
    * Зачистка
    */
    delete [] sum_of_a_parts.values;
    delete [] sum_of_b_parts.values;
    delete [] product_of_sums_of_parts.values;
    delete [] product_of_first_parts.values;
    delete [] product_of_second_parts.values;
  }

  normalize(product); //конечная нормализация числа

  return product;
}
