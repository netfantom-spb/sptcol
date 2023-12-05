#=============Task 1======================================#
class Cabbage:
    def __init__(self, top_leaf_size, step, root_size):
        self.top_leaf_size = top_leaf_size
        self.step = step
        self.root_size = root_size

    def leaf(self):
        # Отрезаем по листику, пока качан не станет меньше (или равен) кочарыжки
        # не очень реалистично, но описанию задачи не противоречит, спишем все на темную материю, 
        if (self.top_leaf_size > self.root_size):
            self.top_leaf_size -= self.step      
            
        # А вот печатаем размер кочана или кочарыжки - в зависимости от того что больше
        print(max(self.top_leaf_size, self.root_size))
       
def run_task1():
    cb = Cabbage(10, 3, 2)
    cb.leaf()
    cb.leaf()
    cb.leaf()
    cb.leaf()
    
    
#=============Task 2======================================#
class Raduga:
    colors = ["red", "orange", "yellow", "green", "light blue", "blue", "violet"]

    def __init__(self, rainbow_type=1):
        if not(rainbow_type in {1,2,3}):
            raise ValueError(f'Неизвестный тип радуги "{rainbow_type}"')
        self.rainbow_type = rainbow_type
        self.current_index = 0

    def next_color(self, color):
        if color not in Raduga.colors:
            raise ValueError(f'Недопустимый цвет "{color}"')

        index = Raduga.colors.index(color)

        if self.rainbow_type in {1,3}:
            next_index = (index + 1) % len(Raduga.colors)
        elif self.rainbow_type == 2:
            next_index = (index - 1) % len(Raduga.colors)
        else:
            raise ValueError(f'Неизвестный тип радуги "{self.rainbow_type}"')

        return Raduga.colors[next_index]

def run_task2():
    try:
        r1 = Raduga(1)
        print(r1.next_color('violet')) 

        r2 = Raduga(2)
        print(r2.next_color('red'))
    except Exception as e:
        print(f'Что-то пошло не так: {e}')

if __name__ == "__main__":
    print("=============Task 1======================================")
    run_task1()
    
    print("=============Task 2======================================")
    run_task2()