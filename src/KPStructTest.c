#include <stdio.h>

typedef struct {
    int index;
    char ** state;
} T_sa_struct;


T_sa_struct sa_struct[2];

int main(int argc, const char* argv[]) {

    T_sa_struct * sa;

    int i;
    for( i = 0; i < 2; i++){
        sa = &sa_struct[ i];
        sa->state = (char**) malloc( 3 * sizeof(char*));
        sa->state[0] = "state1";
        sa->state[1] = "state2";
        sa->state[2] = "state3";
        sa->index = i * i;
        printf( "%d\n", sa->index);
        int j = 0;
        while( sa->state[ j] != NULL){
            printf("\t%s\n", sa->state[j++]);
        }
    }

}
