
from collections import OrderedDict


class Flower:
    def __init__(self, name, color, price):
        self.name = name
        self.color = color
        self.price = price

    def __str__(self):
        return f"{self.color} {self.name} (Цена: {self.price} руб.)"


class Bouquet:
    def __init__(self, name, flowers):
        self.name = name
        self.flowers = flowers

    def get_total_price(self):
        total_price = sum(flower.price * quantity for flower, quantity in self.flowers.items())
        return total_price

    def __str__(self):
        if not self.flowers:
            return "Букет пуст"
        bouquet_description = "\n".join("\t" + f"{flower} {quantity} шт." for flower, quantity in self.flowers.items()) + f"\n\tИтого: {self.get_total_price()} руб."
        return f"{self.name}\n{bouquet_description}"

class Warehouse:
    def __init__(self):
        self.inventory = {}  # Словарь для хранения цветов и их количества

    def add_flower(self, flower, quantity):
        if flower.name in self.inventory:
            self.inventory[flower.name] += quantity
        else:
            self.inventory[flower.name] = quantity

    def remove_flower(self, flower, quantity):
        if flower.name in self.inventory:
            if self.inventory[flower.name] >= quantity:
                self.inventory[flower.name] -= quantity
            else:
                print(f"На складе не хватает {flower.name}")
        else:
            print(f"На складе нет цветов {flower.name}")        

    def __str__(self):
        print()
        inventory = "Остаток н складе:\n" +  "\n".join(f"\t{flower}: {quantity} шт." for  flower, quantity in self.inventory.items())
        return inventory

class FlowerStore:
    def __init__(self, bouquets, warehouse):
        self.__bouquets = bouquets
        self.__warehouse = warehouse

    def show_assortment(self):
        return "Ассортимент букетов:\n" + "\n".join(f"{bouquet}" for bouquet in self.__bouquets)

    def sell_bouquet(self, bouquet_name):
        for bouquet in self.__bouquets:
            if bouquet.name == bouquet_name:
                for flower, quantity in bouquet.flowers.items():
                    self.__warehouse.remove_flower(flower, quantity)
                print(f"Продан букет: {bouquet_name}")
                return
        raise Exception(f"Букет {bouquet_name} не найден")

if __name__ == "__main__":        
    # Ассортимент
    flower1 = Flower("Роза", "Красная", 50)
    flower2 = Flower("Тюльпан", "Желтый", 30)
    flower3 = Flower("Лилия", "Белая", 60)    
    bouquet1 = Bouquet("Романтический букет", OrderedDict([(flower1, 5), (flower2, 10)]))
    bouquet2 = Bouquet("Весенний букет", OrderedDict([(flower2, 8), (flower3, 12)]))
    
    warehouse = Warehouse()
    warehouse.add_flower(flower1, 100)
    warehouse.add_flower(flower2, 30)
    warehouse.add_flower(flower3, 50)
    
    store = FlowerStore([bouquet1, bouquet2], warehouse)
    print(store.show_assortment())
    
    store.sell_bouquet(bouquet1.name)
    store.sell_bouquet(bouquet2.name)
    store.sell_bouquet(bouquet1.name)
    store.sell_bouquet(bouquet2.name)
    store.sell_bouquet(bouquet1.name)
    store.sell_bouquet(bouquet2.name)
