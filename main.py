
class Math:
    def __init__(self, a, b):
        self.a = a
        self.b = b    

    def addition(self):
        result = self.a + self.b
        return result
    
    def multiplication(self):
        result = self.a * self.b
        return result
    
    def division(self):
        if self.b == 0:
            print("Деление на ноль невозможно.")
            return None
        result = self.a / self.b
        return result
    
    def subtraction(self):
        result = self.a - self.b
        return result

[a,b] = [50,10]

math = Math(a,b)
result = math.addition()
print(f'Сложение: {a} + {b} = {result}')
result = math.multiplication()
print(f'Умножение: {a} * {b} = {result}')
result = math.division()
print(f'Деление: {a} / {b} = {result}')
result = math.subtraction()
print(f'Вычитание: {a} - {b} = {result}')
