 #=============Task 1======================================
def run_task1(filename: str):
    try:
        with open(filename, "r") as file:
            data = file.read()
    except FileNotFoundError:
        print("Файл не существует. Выбрасываю исключение.")
        raise 

 #=============Task 2======================================
def run_task2(value: str):
    try:
        number = float(value)
    except ValueError:
        print("Строка не является числом. Выбрасываю исключение.")
        raise ValueError("Строка не является числом")
    return number

 #=============Task 3======================================
class MyCustomClass:
    def __init__(self):
        pass

    def do_something(self, param):
        if not isinstance(param, str) or len(param) > 10:
            raise ValueError("Недопустимый параметр. Параметр должен быть строкой не длиннее 10 символов.")        
        else:
            print('Done')

 #=============Task 4======================================
class CitiesList:
    def __init__(self, input_list):
        if not input_list:
            raise ValueError("Входной список не может быть пустым")
        else:
            self.input_list = input_list        
            print(f'Городов в списке: {len(self.input_list)}')

# print("=============Task 1======================================")
# run_task1('hometask.16-10.py') # Файл существует
# run_task1('file-not-exists') # Файл не существует, выбрасывается исключение

# print("=============Task 2======================================")
# run_task2('1234') # Строка является числом
# run_task2('abcd') # Строка не является числом, выбрасывается исключение
    
# print("=============Task 3======================================")
# instance = MyCustomClass()
# instance.do_something('abc') 
# instance.do_something(37) # Не явлется строкой, выбрасывается исключение
# instance.do_something('abcedfghopqrst') # Строка больше 10 символов, выбрасывается исключение

# print("=============Task 4======================================")
# cities_success = CitiesList(['Москва', 'Казань']) # Все хорошо
# cities_failed = CitiesList([]) # Исходный список пуст, выбрасывается исключение