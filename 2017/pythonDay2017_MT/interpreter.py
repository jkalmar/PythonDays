#!/usr/bin/python
""" Interpreter """

testInput1 = "010100100100"
testInput2 = """001000100010001000100010001000100110000000100010001000100010001000100010000100110111000000100100"""
testInput3 = "00100010001000100010001001100000100010100001001101110000001000100010001000100100"


program = []
data = [0 for x in xrange(0, 99)]
dataPtr = 0
programPtr = 0

def moveLeft():
    global dataPtr
    if dataPtr == 0:
        dataPtr = 99999
    else:
        dataPtr = dataPtr - 1

def moveRight():
    global dataPtr
    if dataPtr == 99999:
        dataPtr = 0
    else:
        dataPtr = dataPtr + 1

def incData():
    if( data[dataPtr] == 255 ):
        data[dataPtr] = 0
    else:
        data[dataPtr] = data[dataPtr] + 1

def decData():
    if( data[dataPtr] == 0 ):
        data[dataPtr] = 255
    else:
        data[dataPtr] = data[dataPtr] - 1

def writeOut():
    print( str(unichr(data[ dataPtr ])))

def readIn():
    data[dataPtr] = 100

def jmpZero():
    global programPtr
    if data[dataPtr] == 0:
        programPtr = program[programPtr][1]

def jmpNoZero():
    global programPtr
    if data[dataPtr] != 0:
        programPtr = program[programPtr][1]

def addInst():
    global programPtr
    global data

    data[dataPtr] = data[dataPtr] + int(instructionsRev[program[programPtr + 1][0]],2)

def subInst():
    pass

def nothing():
    pass

def nullData():
    data[dataPtr] = 0

def resetPtr():
    dataPtr = 0

instructions = {
    "0000" : moveRight,
    "0001" : moveLeft,
    "0010" : incData,
    "0011" : decData,
    "0100" : writeOut,
    "0101" : readIn,
    "0110" : jmpZero,
    "0111" : jmpNoZero,
    "1000" : addInst,
    "1001" : subInst,
    "1010" : nothing,
    "1011" : nullData,
    "1100" : resetPtr
    }

instructionsRev = dict((v,k) for k,v in instructions.iteritems())

def readProgram():
    testInput = testInput3
    print(len(testInput))

    loops = []

    for i in xrange(0, len(testInput), 4):
        if testInput[i:i+4] == "0110":
            loops.append( i / 4 )
            program.append([instructions[testInput[i:i+4]], 1000000])
        elif testInput[i:i+4] == "0111":
            index = loops.pop()
            program.append([instructions[testInput[i:i+4]], index])
            program[index] = [program[index][0], i / 4]
        else:
            program.append([instructions[testInput[i:i+4]], 1000000])

    for i in program:
        print(i)


    if loops:
        print("ERROR")

def execProgram():
    global programPtr

    while programPtr < len(program):
        program[programPtr][0]()
        programPtr = programPtr + 1

def main():
    readProgram()
    execProgram()
    

if __name__ == '__main__':
    main() 
