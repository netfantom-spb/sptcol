class Calculator:
    def add(self, a, b):
        if not (isinstance(a, (int, float)) and isinstance(b, (int, float))):
            raise ValueError("Некорректные данные для операции")
        return a + b

    def subtract(self, a, b):
        if not (isinstance(a, (int, float)) and isinstance(b, (int, float))):
            raise ValueError("Некорректные данные для операции")
        return a - b

    def multiply(self, a, b):
        if not (isinstance(a, (int, float)) and isinstance(b, (int, float))):
            raise ValueError("Некорректные данные для операции")
        return a * b

    def divide(self, a, b):
        if not (isinstance(a, (int, float)) and isinstance(b, (int, float))):
            raise ValueError("Некорректные данные для операции")
        if b == 0:
            raise ZeroDivisionError("Деление на ноль невозможно")
        return a / b

    def power(self, a, b):
        if not (isinstance(a, (int, float)) and isinstance(b, (int, float))):
            raise ValueError("Некорректные данные для операции")
        return a ** b

# Пример использования:
calc = Calculator()

try:
    
    a = 1
    b = 'adsad'
    
    result_add = calc.add(a, b)
    result_subtract = calc.subtract(a, b)
    result_multiply = calc.multiply(a, b)
    result_divide = calc.divide(a, b)
    result_power = calc.power(a, b)

    print("Сумма:", result_add)
    print("Разность:", result_subtract)
    print("Произведение:", result_multiply)
    print("Деление:", result_divide)
    print("Возведение в степень:", result_power)
        
except ValueError as ve:
    print(f"Ошибка: {ve}")

except ZeroDivisionError as zde:
    print(f"Ошибка: {zde}")
