#include <iostream>
#include <string>

// for std::unordered_map which is close to python dictionary
#include <unordered_map>

// for demangle
#include <stdlib.h>
#include <cxxabi.h>

#include <algorithm>

/**
 *  C++ compiler mangles symbols names and this do the opozite.
 *  It is used to demangle typeid::name() so it gets a real type of
 *  an object in human "readable" way
 */
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

/**
 *  Overloaded of operator<< to print any std::unordered_map naturally in c++.
 *  This adds an ability to std::cout ( in general to std::ostream ) to print maps just like
 *  any other elements
 *  Pleane note the complexity of this function compared to java or python, it is in infinitely number of times
 *  more complex because python and java can do out of the box( with no effort ) such a simple thing like 
 *  printing a dictionary
 */
template< class T, class V >
static std::ostream& operator<<( std::ostream& os, const std::unordered_map< T, V >& aMap )
{
    os << "{";

    for( const auto& i : aMap )
    {
        os << "( " << i.first << ": " << i.second << " ) ";
    }

    os << "}";

    return os;
}

/**
 *  Generic helper function to swap keys <-> values in any map
 */
template< class K, class V >
static std::unordered_map< V, K > swapKeysValues( const std::unordered_map< K, V >& aDict )
{
    std::unordered_map< V, K > ret;

    for( const auto& i : aDict )
    {
        ret.emplace( i.second, i.first );
    }

    return ret;
}

int main( int argc, char** argv )
{
    // definition of a dictionary
    std::unordered_map< std::string, std::string > di1;
    std::unordered_map< int, std::string > di2 = { { 1, "one" }, { 2, "two" } };
    std::unordered_map< int, std::string > di3 = { { 3, "three" }, { 4, "four" } };

    std::cout << "Type of di1: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;
    std::cout << "Type of di2: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;
    std::cout << "Type of di3: " << demangle( typeid( di1 ).name() ) << std::endl << std::endl;

    // insert into a dictionary is the same as in python
    di1[ "key" ] = "value";

    std::cout << di1 << std::endl;

    // dictionaries can be merged
    std::unordered_map< int, std::string > di4( di2 );
    di4.insert( di3.begin(), di3.end() );

    std::cout << di4 << std::endl;

    std::unordered_map< std::string, int > di5 = { {"jedna", 1 }, { "dva", 2 }, { "tri", 3 }, { "styri", 4 } };

    // the power of dictionary is in lookups
    std::cout << di4[ di5[ "dva" ] ] << std::endl;

    // There is no native dict comprehension in C++

    // a preto prehodit kluce si vyzaduje trochu kodu
    std::unordered_map< int, std::string > di6 = swapKeysValues( di5 );
    std::cout << "Original di5: " << std::endl;
    std::cout << di5 << std::endl;
    std::cout << "Swapped keys <-> values in di6:" << std::endl;
    std::cout << di6 << std::endl;

    return 0;
}
