#!/usr/bin/python3
""" Python numbers """

def main():
    """ Main func """

    # Python does not have types so definition of a variable is simple assigment
    intnum = 10

    # We can easily print those vars and its internal type ( remember python is dynamic language, but it
    # does not mean it does not support types )
    print("Decimal number: %d" % intnum)
    print("Type of: %s" % type(intnum))

    # floating point
    floatnum = 5.5

    print("Floatin point num: %f" % floatnum)
    print("Type of: %s" % type(floatnum))

    # something nice is that it has out of the box support for large numbers
    big = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000
    print("Big number: %d" % big)
    print("Type of big: %s" % type(big))

    # and it can hangle powers out of the box
    print("Power 2^64: %d" % 2**64)

    # it can also handle sum of very big num and some small
    print("big + intnum: %d" % (big + intnum))

    # some basich math operations
    print("intnum + floatnum: %f" % (intnum + floatnum))
    print("intnum + floatnum: %f" % (intnum - floatnum))
    print("intnum + floatnum: %f" % (intnum * floatnum))
    print("intnum + floatnum: %f" % (intnum / floatnum))
    print("intnum ** 2: %d" %  (intnum ** 2))
    print("intnum %% 3: %d" % (intnum % 3))

    # nice formatted output
    print("Formated output: %010.5f" % floatnum)


    # this is weird, python tells us that 1.1 + 2.2 is not equal to 3.3
    # this I was expecting in c++ byt not in high-level language like python
    if 1.1 + 2.2 == 3.3:
        print("1.1 + 2.2 equal 3.3")
    else:
        print("1.1 + 2.2 non equal 3.3")
        print(1.1 + 2.2)

if __name__ == '__main__':
    main()
