#!/usr/bin/python3
""" Python dictionaries """

def main():
    """
    Dictionary is an associative container that associates key with value and allows
    Fast lookups, inserts and erases.
    They are usually implemented as some kind of a hashtable
    """


    # dictionary in python is symbolized by curly brackets {}
    di1 = {}

    # we can easily init dictionary with a pair of key : value elements
    di2 = {1 : "one", 2 : "two", 3 : "three", 4 : "four", 5 : "five"}
    di3 = {6 : "six", 7 : "seven", 8 : "eight", 9 : "nine", 10 : "ten"}

    print("Type of di1: %s" % type(di1))
    print("Type of di2: %s" % type(di2))
    print("Type of di3: %s" % type(di3))

    # we can add value to a key into dictionary using [] operator
    di1["key"] = "value"

    # printing of a dictionary is native in python
    print(di1)

    # removing a key from a dictionary is easy, however removing by value needs a bit of work
    del di1["key"]

    print(di1)

    # dictionaries can be "merged" together
    # in dictionary the key is unique and as such if di2 and di3 would have two same keys then it would get overwritten
    # by the element from the later dictiornary in this case di4 is first initialized to di2 and then d3 is added
    # so di3 elements with the same key would overwrite elements from di2
    di4 = di2.copy()
    di4.update(di3)
    print("di4: " + str(di4))

    # true power is when it comes to searching
    di5 = {"jedna" : 1, "dva" : 2, "tri" : 3, "styri" : 4}

    # this prints the world two, first it will lookup the value of a key "dva" in di5 which is 2 and then it
    # lookup the key 2 in di4 which is two
    print(di4[di5["dva"]])

    # python supports dictionary comprehension
    di6 = {k: di4[v] for (k, v) in di5.items()}
    print(di6)

    # switching key with values in python's dictionaries is very easy
    di7 = {v: k for (k, v) in di4.items()}
    print(di7)


if __name__ == '__main__':
    main()
