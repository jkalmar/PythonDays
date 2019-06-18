import java.lang.System;

import java.lang.String;

import static java.util.stream.Collectors.*;
import java.util.stream.Stream;


class StringSample
{
    public static String repeat(String str, int times)
    {
        // potrebuje java 8 a vyssiu
        return Stream.generate( () -> str ).limit( times ).collect( joining() );
    }

    public static void main(String[] args) {
        String hello = "Hello";
        String world = "World";

        System.out.println( hello );
        System.out.println( world );

        // retazce sa daju lahko spajat
        System.out.println( hello + world );

        // aj ulozit do novej premmenej
        String concat = hello + world;
        System.out.println( concat );

        // alebo pridat medzera
        System.out.println( hello + " " + world );

        // alebo aj inak od java 8
        //String.join(" ", Collections.nCopies(n, s));

        String helloworld = hello + " " + world;

        // retazce sa daju slicovat
        System.out.println( helloworld.substring( 0, 5) );
        System.out.println( helloworld.substring( 5 ) );

        // retazce sa daju indexovat
        System.out.println( hello.charAt( 4 ) + world.charAt( 0 ) + hello.charAt( 2 ) );

        // mozu sa opakovat ale treba to nakodovat
        System.out.println( repeat( "*", 80 ) );
        System.out.print( repeat( "*" + repeat(" ", 78) + "*\n", 2) );
        System.out.println( "*" + repeat( " ", 78 / 2 - helloworld.length() / 2 - 1 ) + helloworld + repeat( " ", 78 / 2 - helloworld.length() / 2 ) + "*" );
        System.out.print( repeat( "*" + repeat(" ", 78) + "*\n", 3) );
        System.out.println( repeat( "*", 80 ) );

        // vedia kreslit
        int base = 30;
        for( int row = 1; row <= base; row += 2 )
        {
            System.out.println( repeat( " ", base / 2 - row / 2 ) + repeat( "*", row ) );
        }

        //da sa v nich vyhladavat
        System.out.println( "Je hello v Hello World?" );
        System.out.println( helloworld.contains( "hello" ) );

        // pozor vyhladavanie je case-sensitive
        // tak este raz
        System.out.println( "Je hello v Hello World?" );
        System.out.println( helloworld.toLowerCase().contains( "hello" ) );
    }
} 
