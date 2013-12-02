#include <stdio.h>

typedef struct {
    int index;
} T_sa_struct;


T_sa_struct sa_struct[2];

int main(int argc, const char* argv[]) {

    sa_struct[ 0].index = 15;
    sa_struct[ 1].index = 15;

    int i;
    for( i = 0; i < 2; i++)
        printf( "%d\n", sa_struct[ i].index);

}