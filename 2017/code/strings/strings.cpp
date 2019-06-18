#include <iostream>
#include <string>

#include <algorithm>
#include <cctype>

std::string operator*( const std::string& s, size_t n )
{
    std::string r;
    r.reserve(n * s.size());
    for ( size_t i = 0; i < n; i++)
        r += s;
    return r;
}

bool findStringIC( const std::string& strKde, const std::string& strCo )
{
  auto it = std::search( 
      strKde.begin(), strKde.end(), strCo.begin(),   strCo.end(),
      [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
  );
  return ( it != strKde.end() );
}

int main(int argc, char** argv) 
{
    // stringy v c++ su definovane v include <string>
    // c++ poskytuje zakladnu podporu stringov

    // standartna definicia premmenych
    std::string hello = "Hello";
    std::string world = "World";

    // lahko sa daju printovat
    std::cout << hello << std::endl;
    std::cout << world << std::endl;

    // daju sa spajat
    // c++ ma moznost pretazovat operatory a teda std::string ma pretazeny operator+ na spajanie stringov
    std::cout << hello + world << std::endl;

    // samozrejme ulozit do premmenej je hracka
    std::string concat = hello + world;
    std::cout << concat << std::endl;

    // da sa lahko pridat medzera medzi stringy
    std::cout << hello + " " + world << std::endl;

    // nieco ako joinovanie listov v c++ nieje nativne
    
    std::string helloworld = hello + " " + world;

    std::cout << helloworld << std::endl;

    // retazce sa daju trochu divne slicovat
    std::cout << helloworld.substr(0, 5) << std::endl;
    std::cout << helloworld.substr(5, std::string::npos) << std::endl;  

    // aj indexovat, no pozor na to ako c++ interpretuje data, pamatate c++ je typovy jazyk
    std::cout << hello[4] + world[0] + hello[2] << std::endl;

    // toto je to co chceme:
    std::cout << hello[4] << world[0] << hello[2] << std::endl;

    // relativne divne sa daju znaky opakovat
    std::cout << std::string(80, '*') << std::endl;
    std::cout << "*" << std::string( 78, ' ' ) << "*" << std::endl;
    std::cout << std::string( "*" + std::string( 78, ' ' ) + "*\n" ) * 2;
    std::cout << "*" + std::string( (78 / 2 - helloworld.length() / 2 - 1), ' ' ) + helloworld +  std::string( (78 / 2 - helloworld.length() / 2 ), ' ' ) + "*" << std::endl;
    std::cout << std::string( "*" + std::string( 78, ' ' ) + "*\n" ) * 3;
    std::cout << std::string(80, '*') << std::endl;

    // vedia aj kreslit
    int base = 30;
    for( int i = 1; i <= 30; i += 2 )
    {
        std::cout << std::string( base / 2 - i / 2, ' ' ) + std::string( i, '+' ) << std::endl;
    }

    // da sa v nich vyhladavat
    std::cout << "Je hello v Hello World?" << std::endl;
    std::cout << ( helloworld.find( "hello" ) == std::string::npos ? "False" : "True" ) << std::endl;

    // vyhladavanie je tiez case-sensitive
    // da sa dosiahnut aj cese-insensitive len treba trocha programovat
    std::cout << "Je hello v Hello World?" << std::endl;
    std::cout << ( findStringIC( helloworld, "hello" ) == true ? "True" : "False" ) << std::endl;

    return 0;
} 
