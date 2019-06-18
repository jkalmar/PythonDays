#!/usr/bin/python3
""" Python lists """

def main():
    """ Main func """

    # lists can contains multiple elements
    # in python these elements can be anything, to fully appreciate this feature you should tune yourself
    # to python duck typing mentality :)
    li1 = ["list", "set", "dictionary"]
    li2 = ["one", "1", 2, "two", "three", 4, 5]
    li3 = ["str", "hex", "dec"]

    # getting a list type is easy and in all the lists the type is the same: just list
    print("Type of li1: %s" % type(li1))
    print("Type of li2: %s" % type(li2))
    print("Type of li3: %s" % type(li3))

    # elements can be appended to list
    li1.append("added")

    # lists can be very easy printed, no special function needed
    print(li1)

    # elements can be removed from list using .remove method
    li1.remove("added")

    print(li2)

    # lists can be merged using operator+
    li4 = li1 + li2
    print(li4)

    # python has build in support for list comprehension
    # which is creating one list from another list with optional transformation applied on it
    # li5 is a list of elements from li4 that satisfy the condition that li4 elements are integers
    li5 = [x for x in li4 if isinstance(x, int)]
    # li6 is a list of elements from li4 that are strings and contains "a" character
    li6 = [x for x in li4 if isinstance(x, str) and len(x) > 4]
    print(li5)
    print(li6)

if __name__ == '__main__':
    main()
