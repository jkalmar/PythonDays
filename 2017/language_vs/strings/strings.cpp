#include <iostream>
#include <string>

// for std::search
#include <algorithm>

// for std::toupper
#include <cctype>

/**
 *  Overload of operator * to repeat the string multiple time.
 *  With this c++ can mimic python's string repeating feature
 */
std::string operator*( const std::string& s, size_t n )
{
    std::string r;
    r.reserve(n * s.size());
    for ( size_t i = 0; i < n; i++)
        r += s;
    return r;
}

/**
 *  Search the string strWhat in string strWhere.
 *  This searches the string case insensitive
 */
bool inCI( const std::string& strWhat, const std::string& strWhere )
{
    // C++11 syntax, using auto and lambda
    auto it = std::search( 
        strWhere.begin(), strWhere.end(), strWhat.begin(),   strWhat.end(),
        [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
    );

    return ( it != strWhere.end() );
}

int main(int argc, char** argv) 
{
    // c++ defines string in <string> include

    // string definition, in c++ we need to say the type explicitly
    std::string hello = "Hello";
    std::string world = "World";

    // printing is easy
    std::cout << hello << std::endl;
    std::cout << world << std::endl;

    // string can be merged
    // C++ overload the operator+ by default so it is easy to concatena strings
    std::cout << hello + world << std::endl;

    // storying the result into a variable is easy
    // in c++ there is keyword auto which tells the compiler to find the type for us
    // this is something that python does by default
    auto concat = hello + world;
    std::cout << concat << std::endl;

    // adding space is easy
    std::cout << hello + " " + world << std::endl;

    // something like joining list with char is not native in c++
    
    // creating new variable from concat is native
    auto helloworld = hello + " " + world;
    std::cout << helloworld << std::endl;

    // c++ does not have slice operator but the same can be achived using .substr method
    // of string class
    std::cout << helloworld.substr(0, 5) << std::endl;
    std::cout << helloworld.substr(5, std::string::npos) << std::endl;  

    // indexing is easy, but be aware how c++ interpret data -> hint this will not print what you
    // might have expected
    std::cout << "String indexing: " << hello[4] + world[0] + hello[2] << std::endl;

    // this is what we want:
    std::cout << "String indexing 2nd try: " << hello[4] << world[0] << hello[2] << std::endl;

    // c++ has limited repeating functionality by default
    // but by creating a function it becomes more easy
    std::cout << std::string(80, '*') << std::endl;
    std::cout << "*" << std::string( 78, ' ' ) << "*" << std::endl;
    std::cout << std::string( "*" + std::string( 78, ' ' ) + "*\n" ) * 2;
    std::cout << "*" + std::string( (78 / 2 - helloworld.length() / 2 - 1), ' ' ) + helloworld +  std::string( (78 / 2 - helloworld.length() / 2 ), ' ' ) + "*" << std::endl;
    std::cout << std::string( "*" + std::string( 78, ' ' ) + "*\n" ) * 3;
    std::cout << std::string(80, '*') << std::endl;

    // string can draw
    int base = 30;
    for( int i = 1; i <= 30; i += 2 )
    {
        std::cout << std::string( base / 2 - i / 2, ' ' ) + std::string( i, '+' ) << std::endl;
    }

    // searching is supported as well by default
    std::cout << "Is hello in Hello World?" << std::endl;
    std::cout << ( helloworld.find( "hello" ) == std::string::npos ? "False" : "True" ) << std::endl;

    // search is case-sensitive in c++ too
    // but making is case insensite is a matter of one function
    std::cout << "Is hello in Hello World?" << std::endl;
    std::cout << ( inCI( helloworld, "hello" ) == true ? "True" : "False" ) << std::endl;

    return 0;
} 
