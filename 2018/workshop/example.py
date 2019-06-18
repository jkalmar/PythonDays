#!/usr/bin/python3

import ctypes as ct


workshop = CDLL("./workshop.so")

hello = workshop.hello
add = workshop.add
makeCallback = workshop.makeCallback

add.restype = c_int
add.argtypes = [ c_int, c_int ]

str = "from python".encode("utf-8")

strC = c_char_p(str)

hello(strC)


#print( add( 5, 10 ) )

prototype = CFUNCTYPE( c_int, POINTER( c_int ), c_int )


@prototype
def callback( arr, lengt ):
    res = 0

    for i in range(lengt):
        res = res + arr[i]

    return res

makeCallback.restype = c_int
makeCallback.argtypes = [ prototype ]

print( makeCallback( callback ) )
