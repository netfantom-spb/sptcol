import random

#=============Task 1======================================#
class Rectangle:
    def __init__(self, point1, point2):
        self.point1 = point1
        self.point2 = point2

    def perimeter(self):
        x1, y1 = self.point1
        x2, y2 = self.point2
        length = abs(x2 - x1)
        width = abs(y2 - y1)
        return round(2 * (length + width), 2)

    def area(self):
        x1, y1 = self.point1
        x2, y2 = self.point2
        length = abs(x2 - x1)
        width = abs(y2 - y1)
        return round(length * width, 2)
    
def run_task1():
    print("Example 1")
    rect = Rectangle((3.2, -4.3), (7.52, 3.14))
    print("Площадь:", rect.area()) 
    
    print("Example 2")
    rect = Rectangle((7.52, -4.3), (3.2, 3.14))
    print("Периметр:", rect.perimeter()) 

#=============Task 2======================================#
class Tomato:
    states = {
        0: "Отсутствует",
        1: "Цветение",
        2: "Зеленый",
        3: "Красный"
    }

    def __init__(self, index):
        self._index = index
        self._state = 0

    def grow(self):
        if self._state < 3:
            # Добавим ради интереса элемент случайности - помидорки не электрички, по расписанию не созревают
            self._state += random.choice([0,1]); 

    def is_ripe(self):
        return self._state == 3


class TomatoBush:
    def __init__(self, num_tomatoes):
        if (num_tomatoes < 0):
            raise Exception('Антитоматы в этой версии не поддерживаются, число помидоров на кусте должно быть положительным!') 
        elif(num_tomatoes == 0):
            raise Exception('Вы так себе садовод, ни одной помидорки на кусте=(')
            
        self.tomatoes = [Tomato(index) for index in range(1, num_tomatoes + 1)]

    def grow_all(self):
        for tomato in self.tomatoes:
            tomato.grow()

    def all_are_ripe(self):
        return all(tomato.is_ripe() for tomato in self.tomatoes)

    def give_away_all(self):
        self.tomatoes = []


class Gardener:
    def __init__(self, name, plant):
        self.name = name
        self._plant = plant

    def work(self):
        self._plant.grow_all()

    def harvest(self):
        if self._plant.all_are_ripe():
            self._plant.give_away_all()
            print("Урожай собран.")
            return True
        else:
            print("Пока не все помидоры созрели, продолжайте ухаживать за ними.")
            return False

    @staticmethod
    def knowledge_base():
        print("Справка по садоводству:")
        print("1. Поливайте растения регулярно.")
        print("2. Удобряйте почву в нужное время.")
        print("3. Следите за стадиями созревания плодов.")
        print("4. Собирайте урожай, когда все плоды созрели.")

def run_task2():
    try:
        Gardener.knowledge_base()
        bush = TomatoBush(7)
        gardener = Gardener("John", bush)

        gardener.work()
        
        while not gardener.harvest():
            gardener.work()
    except Exception as e:
        print(f'Что-то пошло не так: {e}')
        
    
if __name__ == "__main__":
    print("=============Task 1======================================")
    run_task1()
    
    print("=============Task 2======================================")
    run_task2()