"""
Basic discount module, implements discount class
"""
from enum import Enum
from .discount_exception import ItemIsNowFreeException
from .discount_exception import DiscountNotApplicableException

class Flavor(Enum):
    """
    Enum for discount type, we could use inheritance instead
    """
    Exclusive = 1
    Multiple = 2

class Discount:
    """
    Basic discount class that can be added to Item
    """
    def __init__(self, flavor, value):
        self.flavor = flavor
        self.value = value
        self.absolute = False

    def set_absolute(self):
        """
        Sets this discount as price discount instead of percent discount
        """
        self.absolute = True

    def add_to(self, to_item):
        """
        Adds this discount to Item
        """
        if self.flavor is Flavor.Exclusive:
            if to_item.discount:
                raise DiscountNotApplicableException("Discount could not be applied", self, to_item)

        to_item.discount.append(self)

    def apply(self, to_item):
        """
        Apply this discount to some Item
        """
        price = to_item.price_final

        if self.absolute:
            price -= self.value
        else:
            price -= price * self.value / 100

        if price <= 0:
            raise ItemIsNowFreeException("Discount is too agresive", price, self)

        to_item.price_final = price
