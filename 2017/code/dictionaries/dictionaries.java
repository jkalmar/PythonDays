import java.lang.System;

import java.lang.String;

import static java.util.stream.Collectors.*;
import java.util.stream.Stream;

import java.util.Hashtable;
import java.util.Dictionary;
import java.util.HashMap;

class Dictionaries
{
    public static < K,V > HashMap< V,K > swapKeysValues( HashMap<K,V> map ) {
        HashMap< V,K > rev = new HashMap< V, K >();
        for( HashMap.Entry< K,V > el : map.entrySet() )
        {
            rev.put(el.getValue(), el.getKey());
        }
        
        return rev;
    }

    public static void main(String[] args) {
        HashMap<String, String> di1 = new HashMap< String, String >();
        HashMap<Integer, String> di2 = new HashMap<Integer, String>(){ { put( 1, "one"); put( 2, "two" ); } };
        HashMap<Integer, String> di3 = new HashMap<Integer, String>(){ { put( 3, "three"); put( 4, "four" ); } };

        System.out.println( "Type of di1: " + di1.getClass().getName() );
        System.out.println( "Type of di2: " + di2.getClass().getName() );
        System.out.println( "Type of di3: " + di3.getClass().getName() );

        // Do dictionary sa da pridavat
        di1.put( "kluc", "hodnota" );

        System.out.println( di1 );

        // Z dictionary sa da mazat
        di1.remove("kluc");

        System.out.println( di1 );

        // dictionary sa daju updatovat
        HashMap<Integer, String> di4 = new HashMap< Integer, String >();
        di4.putAll( di2 );
        di4.putAll( di3 );

        System.out.println( di4 );

        // skutocna sila je vo vyhladavani
        HashMap<String, Integer> di5 = new HashMap< String, Integer >() {
            { put( "jedna", 1); put( "dva", 2); put( "tri", 3 ); put( "styri", 4); }
        };

        System.out.println( di4.get( di5.get( "dva" ) ) );

        // java nema dict comprehension

        // prehodenie prvkov
        System.out.println( swapKeysValues( di4 ) );
    }
} 
