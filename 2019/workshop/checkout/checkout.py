"""
Module that implements checkout simulator
"""
from .discount_exception import ItemPriceIsBad


class Checkout:
    """
    Class representing checkout
    """

    def __init__(self):
        self.items = []
        self.discounts = []
        self.total_price = 0


    def add_discount(self, discount):
        """
        Adds discount to one shopping list
        """
        self.discounts.append(discount)

    def add_item(self, item):
        """
        Adds item to list
        """
        if item.price > 0:
            self.items.append(item)
        else:
            raise ItemPriceIsBad("zla cena")

    def calculate_total(self):
        """
        Calculates the total price of items with discounts
        """
        if self.total_price == 0:
            for discount in self.discounts:
                for item in self.items:
                    item.add_discount(discount)

            for item in self.items:
                self.total_price += item.final_price()

        return self.total_price
