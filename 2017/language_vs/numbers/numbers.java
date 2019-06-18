import java.lang.Math;
import java.lang.System;

import java.math.BigInteger;

// In jave everythin needs to be in a class
class Numbers
{
    public static void main(String[] args) {
        // java is typed language so variable needs type
        int intNum = 10;

        // printing is done using System.out.println
        // the ln part in println means that newline will be printed also
        System.out.println( "Decimal number: " + intNum );
        System.out.println( "Type of: " + (( Object )intNum).getClass().getName() );

        float floatNum = 5.5f;

        // Java has BigInteger by default which is nice
        // but not that nice like in python
        BigInteger big = new BigInteger( "10000000000000000000000000000000000000000000000000000000000000000000000000000000000" );

        // it can even print it easily
        System.out.println( "Big: " + big );
        System.out.println( big.getClass().getName() );
        System.out.println( Math.pow( 2, 64) );

        // Adding int to a BigInteger we first need to convert the little int to BigInteger
        // and then add it
        System.out.println( "big + intNum: " + big.add( BigInteger.valueOf( intNum ) ) );

        System.out.println("Float number: " + floatNum);
        System.out.println("Type of: " + (( Object )floatNum).getClass().getName() );

        // formated output is easy, almost the same as in python
        System.out.printf("%010.5f%n", floatNum);

        // basic math operations
        System.out.println( "intNum - floatNum " + ( intNum - floatNum ) );
        System.out.println( intNum * floatNum );
        System.out.println( intNum / floatNum );
        System.out.println( Math.pow(intNum, 2) );
        System.out.println( intNum % 3 );

        // java (like c++ and python) also tells us that 1.1 + 2.2 is not equal to 3.3
        if( 1.1f + 2.2f == 3.3f )
        {
            System.out.println( "1.1 + 2.2 equal 3.3" );
        }
        else
        {
            System.out.println( "1.1 + 2.2 non equal 3.3" );
        }
    }
} 
