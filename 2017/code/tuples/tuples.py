#!/usr/bin/python3
""" Python tuples """

def main():
    """ Main func """
    tu1 = ("list", "set", "dictionary")
    tu2 = ("one", "1", 2, "two", 3, 4, 5)
    tu3 = ("str", "hex", "dec")

    print("Type of tu1: %s" % type(tu1))
    print("Type of tu2: %s" % type(tu2))
    print("Type of tu3: %s" % type(tu3))

    # Do tuplu sa neda pridavat
    # tu1.append("added")
    # print(tu1)

    # Z tuplu sa neda odoberat
    # tu2.remove("1")
    # print(tu2)

    # tuply sa daju spajat
    tu4 = tu1 + tu2
    print(tu4)

    # neexistuje tuple comprehension namiesto toho tento syntax vytvara
    # generatory
    tu5 = (x for x in tu4 if isinstance(x, int))
    tu6 = (x for x in tu4 if isinstance(x, str) and "a" in x)
    print(tu5)
    print(tu6)

    for i in tu5:
        print(i)

    for i in tu6:
        print(i)

if __name__ == '__main__':
    main()
