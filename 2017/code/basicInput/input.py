#!/usr/bin/python3
""" Module """

def one():
    """ One """
    print("Zavolana 1")

def two():
    """ Two """
    print("Zavolana 2")

def three():
    """ Three """
    print("Zavolana 3")


def main():
    """ Main func """
    name = input("Tvoje meno: ")

    print("Tvoje meno je: %s" % name)

    count = input("Kolko krat chces vypisat tvoje meno: ")

    print("%s\n" % name * int(count))

    while True:
        func = input("Ktoru funkciu chces vykonat? ")
        if func == "1":
            one()
        elif func == "2":
            two()
        elif func == "3":
            three()
        elif func.lower() == "ziadnu":
            break
        else:
            print("Zle cislo")

if __name__ == '__main__':
    main()
