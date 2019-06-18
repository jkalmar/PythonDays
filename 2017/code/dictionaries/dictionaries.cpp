#include <iostream>
#include <string>
#include <unordered_map>

#include <stdlib.h>
#include <cxxabi.h>

#include <algorithm>

static std::string demangle(const char *mangled_name)
{
    std::string ret;
    int status = 0;
    const char *realname = abi::__cxa_demangle(mangled_name, 0, 0, &status);
    
    if( status == 0 )
    {
        ret = realname;
    }
    
    free( (void*)realname );
    return ret;
}

template< class T, class V >
static void printDict( const std::unordered_map< T, V >& aMap )
{
    // C++11 syntax
    std::cout << demangle( typeid( aMap ).name() ) << std::endl;
    std::cout << "Dictionary: ";
    for( auto i : aMap )
    {
        std::cout << i.first << " " << i.second << " ";
    }

    std::cout << std::endl;
}

template< class K, class V >
static std::unordered_map< V, K > swapKeysValues( const std::unordered_map< K, V >& aDict )
{
    std::unordered_map< V, K > ret;

    for( auto i : aDict )
    {
        ret.emplace( i.second, i.first );
    }

    return ret;
}

int main( int argc, char** argv )
{
    // definicia hashu
    std::unordered_map< std::string, std::string > di1;
    std::unordered_map< int, std::string > di2 = { { 1, "one" }, { 2, "two" } };
    std::unordered_map< int, std::string > di3 = { { 3, "three" }, { 4, "four" } };

    std::cout << "Type of di1: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;
    std::cout << "Type of di2: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;
    std::cout << "Type of di3: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;

    // do hashu sa da vkladat
    di1[ "kluc" ] = "hodnota";

    printDict( di1 );

    // hashe sa daju spajat
    std::unordered_map< int, std::string > di4( di2 );
    di4.insert( di3.begin(), di3.end() );

    printDict( di4 );

    std::unordered_map< std::string, int > di5 = { {"jedna", 1 }, { "dva", 2 }, { "tri", 3 }, { "styri", 4 } };

    // ich sila je vo vyhladavani
    std::cout << di4[ di5[ "dva" ] ] << std::endl;

    // dict comprehension v c++ neexistuje nativne

    // a preto prehodit kluce si vyzaduje trochu kodu
    std::unordered_map< int, std::string > di6 = swapKeysValues( di5 );
    std::cout << "Povodny di5: " << std::endl;
    printDict( di5 );
    std::cout << "Prehodene kluce a hodnoty v di6:" << std::endl;
    printDict( di6 );

    return 0;
}
