# pylint: disable=redefined-outer-name
"""
Test for Checkout
"""
import pytest

from checkout.checkout import Checkout
from checkout.item import Item
from checkout.discount import Discount
from checkout.discount import Flavor

#from checkout.discount_exception import DiscountNotApplicableException

@pytest.fixture()
def items():
    """
    Fixture that creates a list of items
    """
    milk = Item("Milk", 1.2, 0)
    sugar = Item("Sugar", 0.8, 0)
    candy = Item("Candy", 1.0, 0)

    return [milk, sugar, candy]

@pytest.fixture
def checkout_with_items(items):
    """
    Fixtures that creates a checkout with some items
    """
    checkout = Checkout()

    for item in items:
        checkout.add_item(item)

    return checkout

def test_basic_add(checkout_with_items):
    """
    Basic test that test 3 item without discount
    """
    checkout = checkout_with_items

    total = checkout.calculate_total()

    assert total == 3

    #total = checkout.calculate_total()

    #assert total == 3

def test_with_discount(checkout_with_items):
    """
    Test that checks discount
    """
    checkout = checkout_with_items

    mega_discount = Discount(Flavor.Multiple, 50)

    checkout.add_discount(mega_discount)
    checkout.add_discount(mega_discount)

    assert checkout.calculate_total() == 0.75
