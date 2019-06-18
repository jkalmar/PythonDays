#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef int (*Callback)(int* arr, int len);

void hello ( const char* aStr )
{
    printf ( "Hello: %s", aStr );
}

int add ( int a, int b )
{
    return a + b;
}



int makeCallback( Callback aCallback )
{
    int arr[5] = {1,2,3,4,5};
    int len = 5;

    sleep(1);

    return aCallback(arr, len);
}
