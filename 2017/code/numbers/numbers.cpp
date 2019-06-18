#include <iostream>
#include <typeinfo>
#include <string>

#include <stdlib.h>
#include <cxxabi.h>

#include <limits.h>

#include <math.h>

#include <iomanip>

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
    // Definicia premmenej
    // celociselna
    int cele = 10;

    // desatinna
    float des = 5.5;
    
    // vypis ako print v python
    std::cout << cele << std::endl;

    // v c++ najblizsie k type je typeid no to vyzaduje RTTI zapnute
    // netreba mat starosti to bezne je a treba naincludovat <typeinfo>
    // k tomu aby sme dostali spravny nazov tak treba este vediet "demanglovat"
    // C++ type informaciu do poludstenej podob, na to treba <cxxabi.h>
    std::cout << demangle( typeid( cele ).name() ) << std::endl;

    std::cout << des << std::endl;
    std::cout << demangle( typeid( des ).name() ) << std::endl;

    unsigned long long big = ULLONG_MAX;

    std::cout << big << std::endl;
    std::cout << demangle( typeid( big ).name() ) << std::endl;

    std::cout << pow( 2, 64 )  << std::endl;

    std::cout << "big + cele: " << big + cele << std::endl;

    std::cout << cele + des << std::endl;
    std::cout << cele - des << std::endl;
    std::cout << cele * des << std::endl;
    std::cout << cele / des << std::endl;
    std::cout << pow( 10, 2 ) << std::endl;
    std::cout << cele % 3 << std::endl;

    // na to aby sme mohli potom znova pouzivat std::cout standartne si najprv musime
    // ulozit jeho nastavenie
    std::ios::fmtflags f( std::cout.flags() );

    std::cout << std::fixed << std::setfill('0') << std::setw(10) << std::setprecision(5) << des << std::endl;
    
    // tuna obnovime nastavenie std::cout
    std::cout.flags( f );

    if( 1.1 + 2.2 == 3.3 )
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "non equal" << std::endl;
        std::cout << 1.1 + 2.2 << std::endl;
    }

    // nesmieme zabudnut na return 0 inak budeme "neslusny"
    return 0;
}