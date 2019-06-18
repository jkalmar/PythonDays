#!/usr/bin/python3
""" Python lists """

def main():
    """ Main func """
    li1 = ["list", "set", "dictionary"]
    li2 = ["one", "1", 2, "two", 3, 4, 5]
    li3 = ["str", "hex", "dec"]

    print("Type of li1: %s" % type(li1))
    print("Type of li2: %s" % type(li2))
    print("Type of li3: %s" % type(li3))

    # Do listu sa da pridavat
    li1.append("added")

    print(li1)

    # Z listu sa da odoberat
    li2.remove("1")

    print(li2)

    # listy sa daju spajat
    li4 = li1 + li2
    print(li4)

    # s listami sa dajui robit zaujimave veci
    # list comprehension
    li5 = [x for x in li4 if isinstance(x, int)]
    li6 = [x for x in li4 if isinstance(x, str) and "a" in x]
    print(li5)
    print(li6)

if __name__ == '__main__':
    main()
