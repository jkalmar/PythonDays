#include <iostream>
#include <string>

// for typeid
#include <typeinfo>

// malloc/free
#include <stdlib.h>
// abi::__cxa_demangle - warning highly unportable
#include <cxxabi.h>

// type limits
#include <limits.h>

// std::pow
#include <cmath>

// std::cout manipulation flags
#include <iomanip>


/**
 *  C++ compiler mangles symbols names and this do the opozite.
 *  It is used to demangle typeid::name() so I get a real type of
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

int main(int argc, char** argv) 
{
    // Variable definitions, c++ need to know the type
    // integers
    int integer = 10;

    // floating points
    float decimal = 5.5;
    
    // printing is simple, python by default adds a newline but in c++ we have to
    // add it if needed/wanted
    std::cout << integer << std::endl;

    // To get a type in c++ <typeinfo> is needed and also a funtion to demangle the
    // mangled name of the symbol, this is where <cxxabi.h> is useful
    std::cout << demangle( typeid( integer ).name() ) << std::endl;

    std::cout << decimal << std::endl;
    std::cout << demangle( typeid( decimal ).name() ) << std::endl;

    // in normal c++ the biggest variable size is 64bit
    unsigned long long big = ULLONG_MAX;

    std::cout << big << std::endl;
    std::cout << demangle( typeid( big ).name() ) << std::endl;

    // c++ does not have build in syntax for powers but it has standart function for it
    std::cout << std::pow( 2, 64 )  << std::endl;

    // adding some number to maximum number result in overflow
    std::cout << "big + integer: " << big + integer << std::endl;

    // simple math is done easily
    std::cout << integer + decimal << std::endl;
    std::cout << integer - decimal << std::endl;
    std::cout << integer * decimal << std::endl;
    std::cout << integer / decimal << std::endl;
    std::cout << std::pow( 10, 2 ) << std::endl;
    std::cout << integer % 3 << std::endl;

    // to have some specially formated output first current output config needs to be stored
    std::ios::fmtflags f( std::cout.flags() );

    // then using manipulators configured to print how we want/need it
    std::cout << std::fixed << std::setfill('0') << std::setw(10) << std::setprecision(5) << decimal << std::endl;
    
    // after printing reset the config, this is important because c++ std::cout would keep on printing
    // everything using our formating
    std::cout.flags( f );

    // c++ can only aproximate decimal numbers so apparently 1.1 + 2.2 is aproximated that
    // it is not equal to 3.3
    // explained here:
    // http://floating-point-gui.de/
    if( 1.1 + 2.2 == 3.3 )
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "non equal" << std::endl;
        std::cout << 1.1 + 2.2 << std::endl;
    }

    // Always politely return something to OS
    return 0;
}