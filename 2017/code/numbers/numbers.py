#!/usr/bin/python3
""" Python numbers """

def main():
    """ Main func """
    
    # Python does not have types so definition of a variable is simple assigment
    decimalNum = 10

    # We can easyli print those vars and its internal type ( remember python is dynamic language, but it
    # does not mean it does not support types )
    print("Decimal number: %d" % decimalNum)
    print("Type of: %s" % type(decimalNum))

    # floating point
    floatingPointNum = 5.5

    print("Floatin point num: %f" % floatingPointNum)
    print("Type of: %s" % type(floatingPointNum))

    # something nice is that it has out of the box support for large numbers
    big = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000
    print("Big number: %d" % big)
    print("Type of big: %s" % type(big))

    # and it can hangle powers out of the box
    print("Power 2^64: %d" % 2**64)

    # it can also handle sum of very big num and some small
    print("big + decimalNum: %d" % (big + decimalNum))

    # some basich math operations
    print("decimalNum + floatingPointNum: %f" % (decimalNum + floatingPointNum))
    print("decimalNum + floatingPointNum: %f" % (decimalNum - floatingPointNum))
    print("decimalNum + floatingPointNum: %f" % (decimalNum * floatingPointNum))
    print("decimalNum + floatingPointNum: %f" % (decimalNum / floatingPointNum))
    print("decimalNum ** 2: %d" %  (decimalNum ** 2))
    print("decimalNum %% 3: %d" % (decimalNum % 3))

    # nice formatted output
    print("Formated output: %010.5f" % floatingPointNum)


    # this is weird, python tells us that 1.1 + 2.2 is not equal to 3.3
    if 1.1 + 2.2 == 3.3:
        print("1.1 + 2.2 equal 3.3")
    else:
        print("1.1 + 2.2 non equal 3.3")
        print(1.1 + 2.2)

if __name__ == '__main__':
    main()
