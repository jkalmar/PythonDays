#!/usr/bin/python3
""" Python dictionaries """

def main():
    """ Main func """
    # dictionari alebo hashmap popripadne unordered map je asotiativny kontainer
    # kde kazdy kluc ma nejaku prisluchajucu hodnotu

    di1 = {}
    di2 = {1 : "one", 2 : "two", 3 : "three", 4 : "four", 5 : "five"}
    di3 = {6 : "six", 7 : "seven", 8 : "eight", 9 : "nine", 10 : "ten"}

    print("Type of di1: %s" % type(di1))
    print("Type of di2: %s" % type(di2))
    print("Type of di3: %s" % type(di3))

    # Do dictionary sa da pridavat
    di1["kluc"] = "hodnota"

    print(di1)

    # Z dictionary sa da mazat
    del di1["kluc"]

    print(di1)

    # dictionary sa daju updatovat
    di4 = di2.copy()
    di4.update(di3)
    print(di4)

    # skutocna sila je vo vyhladavani
    di5 = {"jedna" : 1, "dva" : 2, "tri" : 3, "styri" : 4}

    print(di4[di5["dva"]])

    # pripadne trochu dict comprehension
    di6 = {k: di4[v] for (k, v) in di5.items()}
    print(di6)

    # ako lahko sa daju prehodit kluce za hodnoty
    di7 = {v: k for (k, v) in di4.items()}
    print(di7)


if __name__ == '__main__':
    main()
