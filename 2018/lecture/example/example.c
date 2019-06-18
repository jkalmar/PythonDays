#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char* version;
    char* name;
}Data;

int add( int a, int b )
{
    return a + b;
}

// Dynamicky alokovene polia
// Pole je vlastne pole pointrov na polia a teda 2d pole
int matrixAdd( int** a, int** b, int** res, int n, int m )
{
    for( int i = 0; i < n; ++i )
    {
        for( int y = 0; y < m; ++y )
        {
            res[i][y] = a[i][y] + b[i][y];
        }
    }

    return 1;
}

// Dynamicky alokovene polia
// Pole je ale jedna velka oblast v pameti a index musi byt vypocitany cim vlastne simulujeme 2d pole
int matrixAdd2( int* a, int* b, int* res, int x, int y )
{
    /*for( int i = 0; i < x; ++i )
    {
        for( int j = 0; j < y; ++j )
        {
            // Tu si vypocitame index
            res[ j + i*y ] = a[ j + i*y ] + b[ j + i*y ];
        }
    }*/

    // kludne by sme mohli spravit aj toto:
    for( int i = 0; i < x*y; ++i )
    {
        res[ i ] = a[ i ] + b[ i ];
    }

    return 1;
}

Data info( Data* d )
{
    printf( "Caller is: %s %s\n", d->name, d->version );
    // kedze C a Python pouzivaju rozne funkcie na vypis na obrazovku a maju rozne buffre tak treba urobit
    // flush aby sa nam text zobrazil
    fflush(stdout);


    Data about;
    about.name = "GCC";
    about.version = __VERSION__;

    return about;
}





