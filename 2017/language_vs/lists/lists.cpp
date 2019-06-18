#include <iostream>
#include <list>
#include <string>

#include <stdlib.h>
#include <cxxabi.h>

#include <algorithm>

/**
 *  C++ compiler mangles symbols names and this do the opozite.
 *  It is used to demangle typeid::name() so it gets a real type of
 *  an object in human "readable" way
 */
static std::string demangle( const char *mangled_name )
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
 *  Overloaded of operator<< to print any list naturally in c++.
 *  This adds an ability to std::cout ( in general to std::ostream ) to print lists just like
 *  any other elements
 *  Pleane note the complexity of this function compared to java or python, it is in infinitely number of times
 *  more complex because python and java can do out of the box( with no effort ) such a simple thing like 
 *  printing a list
 */
template< class T >
static std::ostream& operator<<( std::ostream& os, const std::list< T > aList )
{
    for( const auto& i : aList )
    {
        os << i << " ";
    }

    return os;
}

int main( int argc, char** argv )
{
    // definition of a list
    // in c++ every variable has to have a type
    // as a result of this, we can not easily ( easily is a key here!!! ) store
    // elements of different types into a single list, which kind of sucks
    // also the nice curly brackets initialization of a list is only possible from C++11
    std::list<int> li1 = { 1,2,3,4,5 };
    std::list<std::string> li2 = { "one", "two", "three" };
    std::list<std::string> li3 = { "list", "set", "dictionary"};

    // geting a type of list is king of easy if we know how to do it
    // but just look what it prints and compare that to python or java
    std::cout << demangle( typeid( li1 ).name() ) << std::endl;
    std::cout << demangle( typeid( li2 ).name() ) << std::endl;
    std::cout << demangle( typeid( li3 ).name() ) << std::endl;

    // adding element to list is easy
    li1.push_back( 10 );

    // printing feels natural ( at least for c++ developers ) if we define a method for it
    std::cout << "li4: " << li1 << std::endl;

    // removing element from list is easy
    li1.remove( 5 );

    std::cout << "li4: " << li1 << std::endl;

    // lists can be relatively easy merged
    std::list< std::string > li4( li2 );
    li4.insert( li4.end(), li3.begin(), li3.end() );

    std::cout << "li4: " << li4 << std::endl;

    // C++ does not have list comprehension like python, but c++ has standard algorithm, which can
    // be used to accomplish this, in c++11 this actually looks very nice
    std::list< std::string > li5;
    std::copy_if( li4.begin(), li4.end(), std::back_inserter( li5 ), []( const std::string& el ){ return el.length() > 4; } );

    std::cout << "li5: " << li5 << std::endl;

    return 0;
} 
