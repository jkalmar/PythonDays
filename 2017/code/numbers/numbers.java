import java.lang.Math;
import java.lang.System;

import java.math.BigInteger;

// V jave je vsetko objekt a teda vsetko musi byt zabalene v class
class Numbers
{
    public static void main(String[] args) {
        int cele = 10;

        System.out.println( "Decimal number: " + cele );
        System.out.println( "Type of: " + (( Object )cele).getClass().getName() );

        float des = 5.5f;

        BigInteger big = new BigInteger( "10000000000000000000000000000000000000000000000000000000000000000000000000000000000" );

        System.out.println( "Big: " + big );
        System.out.println( big.getClass().getName() );
        System.out.println( Math.pow( 2, 64) );

        System.out.println( "big + cele: " + big.add( BigInteger.valueOf( cele ) ) );

        System.out.println("Float number: " + des);
        System.out.println("Type of: " + (( Object )des).getClass().getName() );

        System.out.printf("%010.5f%n", des);

        System.out.println( "cele - des " + ( cele - des ) );
        System.out.println( cele * des );
        System.out.println( cele / des );
        System.out.println( Math.pow(cele, 2) );
        System.out.println( cele % 3 );

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
