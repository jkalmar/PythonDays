import java.lang.System;
import java.lang.String;

import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Collections;
import java.util.stream.Stream;

class StringSample
{
    /**
     * Method for repeating the string N times
     * same as c++ operator* or python build in string multiplication
     */
    public static String repeat(String str, int times)
    {
        // needs java 8 or higher
        return Stream.generate( () -> str ).limit( times ).collect( Collectors.joining() );
    }

    public static void main(String[] args) {
        String hello = "Hello";
        String world = "World";

        System.out.println( hello );
        System.out.println( world );

        // Strings can be easily merged
        System.out.println( hello + world );

        // String can be stored into a variable
        String concat = hello + world;
        System.out.println( concat );

        // Adding space is easy
        System.out.println( "Operator+: " + hello + " " + world );

        // from Java 8 there is a String.join method that do the same aj python "".join() syntax
        System.out.println( "String.join(): " + String.join(" ", Arrays.asList( hello, world ) ) );

        String helloworld = hello + " " + world;

        // string slicing à la Java
        System.out.println( helloworld.substring( 0, 5) );
        System.out.println( helloworld.substring( 5 ) );

        // indexing à la Java
        // This syntax charAt fells very unnatural for C programmer
        System.out.println( hello.charAt( 4 ) + world.charAt( 0 ) + hello.charAt( 2 ) );

        // String can be repeated but you have to code it
        System.out.println( repeat( "*", 80 ) );
        System.out.print( repeat( "*" + repeat(" ", 78) + "*\n", 2) );
        System.out.println( "*" + repeat( " ", 78 / 2 - helloworld.length() / 2 - 1 ) + helloworld + repeat( " ", 78 / 2 - helloworld.length() / 2 ) + "*" );
        System.out.print( repeat( "*" + repeat(" ", 78) + "*\n", 3) );
        System.out.println( repeat( "*", 80 ) );

        // String can draw
        int base = 30;
        for( int row = 1; row <= base; row += 2 )
        {
            System.out.println( repeat( " ", base / 2 - row / 2 ) + repeat( "*", row ) );
        }

        // searching is supported as well by default
        System.out.println( "Is hello in Hello World?" );
        System.out.println( helloworld.contains( "hello" ) );

        // search is case-sensitive in java too, luckily java has methods for case insensitive search 
        System.out.println( "Is hello in Hello World?" );
        System.out.println( helloworld.toLowerCase().contains( "hello" ) );
    }
} 
