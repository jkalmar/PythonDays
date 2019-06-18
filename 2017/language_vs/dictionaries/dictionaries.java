import java.lang.System;
import java.lang.String;

import java.util.Hashtable;
import java.util.Dictionary;
import java.util.HashMap;

import java.util.stream.Collectors;
import java.util.stream.Stream;

class Dictionaries
{
    public static void main(String[] args) {
        // In java everything needs to have its type so we need to say that we want a HashMap and then
        // create one using the new operator
        // Java can infer the type if we do not put anything into the map    
        HashMap<String, String> di1 = new HashMap<>();

        // in java the HashMap can not be directly initialized
        HashMap<Integer, String> di2 = new HashMap<>();
        di2.put( 1, "one");
        di2.put( 2, "two" );

        // if map is initialized like this then java actually creates a new annonymous clas and assing it
        // to the di3 variable, which can be seen in the Type of di2 and di3 -> hint they should be the same
        HashMap<Integer, String> di3 = new HashMap<Integer, String>(){ { put( 3, "three"); put( 4, "four" ); } };

        System.out.println( "Type of di1: " + di1.getClass().getName() );
        System.out.println( "Type of di2: " + di2.getClass().getName() );
        System.out.println( "Type of di3: " + di3.getClass().getName() );

        // simple adding key: value into a dictionary using .put method
        di1.put( "key", "value" );

        System.out.println( di1 );

        // removing a key is done using .remove method
        di1.remove("key");

        System.out.println( di1 );

        // dictionary can be updated and merged using .putAll method which works the same as in python operator+
        HashMap<Integer, String> di4 = new HashMap< Integer, String >();
        di4.putAll( di2 );
        di4.putAll( di3 );

        System.out.println( di4 );

        // true power is in lookups
        HashMap<String, Integer> di5 = new HashMap< String, Integer >() {
            { put( "jedna", 1); put( "dva", 2); put( "tri", 3 ); put( "styri", 4); }
        };

        // this will print "two" and it works the same as python equivalent
        System.out.println( di4.get( di5.get( "dva" ) ) );

        // java does not has dictionary comprehension but java 8 has streams which can be used for this
        HashMap< String, String > di6 = new HashMap<>();
        di5.entrySet().stream().forEach( e -> di6.put( e.getKey(), di4.get( e.getValue() ) ) );

        System.out.println( "di6: " + di6 );

        // also swapping keys with values is easy with streams
        HashMap< String, Integer > di7 = new HashMap<>();
        di4.entrySet().stream().forEach( e -> di7.put( e.getValue(), e.getKey() ) );

        // printing of the swapped dictionary di7 key is string and value is a number but in the 
        // original di4 the key is a number and value is a string
        System.out.println( "swapped keys <-> values in di7: " + di7 );
    }
} 
