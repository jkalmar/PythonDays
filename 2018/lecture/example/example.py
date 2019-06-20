#!/usr/bin/python3

import ctypes as ct

import sys

def printMatrix( matrix, m, n ):
    for i in range(m):
        for j in range(n):
            print( matrix[i][j], end=" " )

        print( "" )

    print()


def printMatrix2( matrix, x, y ):
    for i in range(x):
        for j in range(y):
            print( matrix[ j + i * y ], end=" " )

        print( "" )

    print()

def matrix( func ):
    print( "----------- matrix -----------" )
    m = 5
    n = 3

    INT = ct.c_int
    PINT = ct.POINTER( INT )
    PPINT = ct.POINTER( PINT )

    func.argstype = [ PPINT, PPINT, PPINT, INT, INT ]
    func.restype = INT

    # create a matrix arrays
    INTARR = INT * n
    PINTARR = PINT * m


    ptr = PINTARR()


    for i in range(m):
        ptr[i] = INTARR()
        for j in range(n):
            ptr[i][j] = i + j

    ptr2 = PINTARR()

    for i in range(m):
        ptr2[i] = INTARR()
        for j in range(n):
            ptr2[i][j] = i + j

    # res
    ptr3 = PINTARR()

    for i in range(m):
        ptr3[i] = INTARR()
        for j in range(n):
            ptr3[i][j] = 0

    print( func( ptr, ptr2, ptr3, m, n ))

    printMatrix( ptr, m, n )
    printMatrix( ptr2, m, n )
    printMatrix( ptr3, m, n )


def matrix2( func ):
    print("----------- matrix2 -----------")

    x = 5
    y = 3

    INT = ct.c_int
    PINT = ct.POINTER( INT )

    func.argstype = [ PINT, PINT, PINT, INT, INT ]
    func.restype = INT

    # create a matrix arrays
    ARRXY = INT * ( y * x)

    ptr = ARRXY()

    for i in range(x):
        for j in range(y):
            ptr[ j + i * y ] = i + j

    ptr2 = ARRXY()

    for i in range(x):
        for j in range(y):
            ptr2[ j + i * y ] = i + j

    # res
    ptr3 = ARRXY()

    for i in range(x):
        for j in range(y):
            ptr3[ j + i * y ] = 0

    print(func( ptr, ptr2, ptr3, x, y ))

    printMatrix2( ptr, x, y )
    printMatrix2( ptr2, x, y )
    printMatrix2( ptr3, x, y )

class Data( ct.Structure ):
    _fields_ = [
        ("version", ct.POINTER(ct.c_char)),
        ("name", ct.c_char_p)
    ]

def exchangeInfo( func ):
    print( "----------- exchangeInfo -----------" )


    name = "Python".encode("utf-8")
    version = sys.version.encode("utf-8")

    ourInfo = Data()

    ourInfo.name = name
    ourInfo.version = ct.cast( version, ct.POINTER(ct.c_char) )

    func.argstype = [ ct.POINTER(Data) ]
    func.restype = Data

    sys.stdout.flush()

    theirInfo = func( ct.byref(ourInfo))

    print( "We called: " + theirInfo.name.decode("utf-8") )
    print( ct.string_at( theirInfo.version ).decode("utf-8"))

def main():
    example = ct.CDLL("./example.so")

    add = example.add;
    matrixAdd = example.matrixAdd
    matrixAdd2 = example.matrixAdd2
    infof = example.info

    add.argstype = [ ct.c_int, ct.c_int ]
    add.restype = ct.c_int

    print( add(4,5) )

    matrix(matrixAdd)
    matrix2(matrixAdd2)
    exchangeInfo( infof )

if __name__ == "__main__":
    main()
