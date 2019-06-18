#!/usr/bin/python3
""" Python strings """

def main():
    """ Main func """
    hello = "Hello"
    world = "World"

    print(hello)
    print(world)

    # strings can be merged using + operator
    print(hello + world)

    # also creating a new var using + operator
    concat = hello + world
    print(concat)

    # space can be added easily
    print(hello + " " + world)

    # or a little differently
    # but this first creates a list from the two strings and then
    # join the list into a string using space
    print(" ".join([hello, world]))

    # this do the same but without the middle man
    helloworld = hello + " " + world

    print(helloworld)

    # string slicing is nice
    print("substring from 0 to 5th char: " + helloworld[:5])
    print("substring from 5 to the rest of var: " + helloworld[5:])

    # indexing is natural(at least for C developers :) )
    print(hello[4] + world[0] + hello[2])

    # nice feature is that the operator * repeates the whole string
    print("*" * 80)
    print("*" + " " * 78 + "*")
    print(("*" + " " * 78 + "*\n") * 2, end='')
    print("*" + " "* int(78 / 2 - len(helloworld) / 2) + helloworld + " " * int(78 / 2 - len(helloworld) / 2 + 1) + "*")
    print(("*" + " " * 78 + "*\n") * 3, end='')
    print("*" * 80)

    # strings can draw in the terminal
    base = 30
    for row in range(1, base, 2):
        print(" " * int(base / 2 - row / 2) + "+" * row)

    # searching string in another string is very natural
    print("Is hello in Hello World?")
    print("hello" in helloworld)

    # but please note that seach is case-sensitive
    # so ones more
    print("Is hello in Hello World?")
    print("hello" in helloworld.lower())

if __name__ == '__main__':
    main()

