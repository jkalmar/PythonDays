"""
Module implementing item
"""
from .discount_exception import ItemIsNowFreeException

class Item:
    """
    Class representing one item that can be added to checkout
    """
    def __init__(self, name, price, kind):
        self.name = name
        self.price = price
        self.price_final = price
        self.kind = kind
        self.discount = []

    def add_discount(self, discount):
        """
        Adds discount to Item
        """
        discount.add_to(self)

    def final_price(self):
        """
        Calculates the price of this Item after all discounts is aplied
        """
        for discount in self.discount:
            discount.apply(self)
      

        return self.price_final
