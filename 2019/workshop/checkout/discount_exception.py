"""
Module for discount exceptions
"""

class ItemIsNowFreeException(Exception):
    """
    Exception when Item price is too low (<= 0)
    """
    def __init__(self, message, price, discount):
        super(ItemIsNowFreeException, self).__init__(message)
        self.price = price
        self.discount = discount

class DiscountNotApplicableException(Exception):
    """
    Exception when not compatible discounts are applied to item
    """
    def __init__(self, message, discount, item):
        super(DiscountNotApplicableException, self).__init__(message)
        self.discount = discount
        self.item = item
