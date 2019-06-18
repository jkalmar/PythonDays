#include <iostream>
#include <list>
#include <string>

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

template< class T >
static void printList( const std::list< T >& aList )
{
    // C++11 syntax
    std::cout << demangle( typeid( aList ).name() ) << std::endl;
    std::cout << "List: ";
    for( auto i : aList )
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main( int argc, char** argv )
{
    // definicia listu
    // v c++ musime povedat ake typy chceme ukladat v liste
    // a teda nieje normalne mozne ulozit cisla aj stringy
    // initializacia listu hodnotami je mozna iba od C++11
    std::list<int> li1 = { 1,2,3,4,5 };
    std::list<std::string> li2 = { "one", "two", "three" };
    std::list<std::string> li3 = { "list", "set", "dictionary"};

    std::cout << demangle( typeid( li1 ).name() ) << std::endl;
    std::cout << demangle( typeid( li2 ).name() ) << std::endl;
    std::cout << demangle( typeid( li3 ).name() ) << std::endl;

    // do listu sa da lahko pridavat

    li1.push_back( 10 );

    printList( li1 );

    // z listu sa da odoberat

    li1.remove( 5 );

    printList( li1 );

    // listy sa daju spajat

    std::list< std::string > li4( li2 );
    li4.insert( li4.end(), li3.begin(), li3.end() );

    printList( li4 );

    // neda sa robit priamo list comprehension
    // ale daju sa kopirovat do noveho na zaklade nejakych predikatov
    std::list< std::string > li5;
    std::copy_if( li4.begin(), li4.end(), std::back_inserter( li5 ), []( const std::string& el ){ return el.length() > 4; } );

    printList( li5 );

    return 0;
} 
