#!/usr/bin/python3
""" Python strings """

def main():
    """ Main func """
    hello = "Hello"
    world = "World"

    print(hello)
    print(world)

    # retazce sa daju spajat
    print(hello + world)

    # aj ulozit do premenny
    concat = hello + world
    print(concat)

    #alebo pridat medzera
    print(hello + " " + world)

    #alebo inak
    print(" ".join([hello, world]))

    helloworld = hello + " " + world

    print(helloworld)

    # retazce sa daju slicovat
    print(helloworld[:5])
    print(helloworld[5:])

    # alebo indexovat
    print(hello[4] + world[0] + hello[2])

    # mozu sa opakovat
    print("*" * 80)
    print("*" + " " * 78 + "*")
    print(("*" + " " * 78 + "*\n") * 2, end='')
    print("*" + " "* int(78 / 2 - len(helloworld) / 2) + helloworld + " " * int(78 / 2 - len(helloworld) / 2 + 1) + "*")
    print(("*" + " " * 78 + "*\n") * 3, end='')
    print("*" * 80)

    # vedia kreslit
    base = 30
    for row in range(1, 30, 2):
        print(" " * int(base / 2 - row / 2) + "+" * row)

    #da sa v nich vyhladavat
    print("Je hello v Hello World?")
    print("hello" in helloworld)

    # pozor vyhladavanie je case-sensitive
    # tak este raz
    print("Je hello v Hello World?")
    print("hello" in helloworld.lower())

if __name__ == '__main__':
    main()

