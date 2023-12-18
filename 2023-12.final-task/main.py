import ctypes
import time

# Загрузка библиотеки
pi_lib = ctypes.CDLL('./pi_calculation.so')

# Определение типа аргумента и возвращаемого значения
pi_lib.calculatePi.argtypes = [ctypes.c_int]
pi_lib.calculatePi.restype = ctypes.c_double


def calculate_pi(iterations):
    start_time = time.time() # фиксируем текущее время, чтобы потом посчитать длительность операции
    result = pi_lib.calculatePi(iterations) # вызываем метод calculatePi из библиотеки C++
    end_time = time.time() # фиксируем время в момент завершения функции calculatePi
    print(
        f"Вычисление числа Пи методом Монте-Карло с {iterations} итерациями заняло {end_time - start_time:.5f} секунд")
    return result


if __name__ == '__main__':
    defaultIterationsCount = 100000000  # число итераций по умолчанию
    try:
        print(
            '''Метод Монте-Карло — это численный метод, который использует случайные числа для решения задач, основанных на вероятности. 
На вход в метод задается количество итераций. Чем больше число итераций, тем выше будет точность вычисления, но тем  больше времени оно займет.  
'''
        )
        # Запрашиваем ввод количества итераций
        input = input(
            f"Введите количество итераций для вычисления числа Пи(по умолчанию {defaultIterationsCount}): ")
        if (input == ''): # если пользователь просто нажал ввод
            iterations = defaultIterationsCount # задачем число итераций по умолчванию
        # проверяем что то что пользователь ввел - это целое положительное число больше 0
        elif (input.isdigit() and int(input) > 0):
            iterations = int(input)
        else:
            raise ValueError("Введите положительное число.")
        pi_value = calculate_pi(iterations) # вызываем метод для калькуляции
        print(f"Приближенное значение числа Пи: {pi_value}")
    except ValueError as e:
        print(f"Ошибка: {e}")
