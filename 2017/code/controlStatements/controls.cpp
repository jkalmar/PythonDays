#include <iostream>

int main( int argc, char **argv )
{
    int control = 3;
    
    if( control )
    {
        std::cout << "if berie 3 ako true" << std::endl;
    }
    
    
    if( control == 1 )
    {
        std::cout << "1 sa nerovna 3" << std::endl;
    }
    else
    {
        std::cout << "else vetva zabrala" << std::endl;
    }
    
    if( control == 1 )
        std::cout << "1 sa nerovna 3" << std::endl;
    else
        std::cout << "else vetva zabrala, zatvorky su nepovinne ked sa je iba jeden riadok za if alebo else" << std::endl;
    
    if( control != 1 )
        std::cout << "1 sa nerovna 3" << std::endl;
    else
        std::cout << "else vetva zabrala, zatvorky su nepovinne ked sa je iba jeden riadok za if alebo else" << std::endl;
        std::cout << "ako je vidiet tak chyba moze nastat lahko" << std::endl;
        
    if( control == 1 )
    {
        std::cout << "1 sa nerovna 3" << std::endl;
    }
    else if( control == 3 )
    {
        std::cout << "3 sa rovna 3" << std::endl;
    }
    else
    {
        std::cout << "else sa nezavola" << std::endl;
    }
    
    switch( control )
    {
        case 1:
            std::cout << "1" << std::endl;
            break;
        case 2:
            std::cout << "2" << std::endl;
            break;
        case 3:
            std::cout << "3" << std::endl;
            break;
        default:
            std::cout << "nieco ine" << std::endl;
    }
    
    return 0;
    
}
