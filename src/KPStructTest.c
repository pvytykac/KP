#include <stdio.h>
#include <stdlib.h>

int sa_index = 0;

typedef struct{
    int index;
    char * name;
} T_ENUM;


typedef struct{
    char * name;
    char * sig;
} T_CLASS_OBJECT;

typedef struct {
    int index;
    char * name;
    int state_cnt;
    T_ENUM * states;
    int event_cnt;
    T_ENUM * events;
    T_CLASS_OBJECT * methods;
    T_CLASS_OBJECT * fields;
} T_SA;

T_SA* createSa( char*);
void freeSa( T_SA*);
void addState( T_SA*, char*);
void printSa( T_SA*);
void addEvent( T_SA*, char*);

int main(int argc, const char* argv[]) {

    T_SA * sa = createSa( "sa1");

    addState( sa, "state1");
    addState( sa, "state2");
    addState( sa, "state3");

    addEvent( sa, "event1");
    addEvent( sa, "event2");
    addEvent( sa, "event3");
	
    printSa( sa);
	freeSa( sa);

    T_SA * sa2 = createSa( "sa2");
    addState( sa2, "state1");
	addState( sa2, "state2");
	
	addEvent( sa2, "event1");
	addEvent( sa2, "event2");
	
	printSa( sa2);
	freeSa( sa2);
	
	T_SA * sa3 = createSa( "sa2");
    addState( sa3, "state1");
	
	addEvent( sa3, "event1");
	
	printSa( sa3);
	freeSa( sa3);
}

T_SA* createSa( char* name){
	printf("creating state machine...\n");
    T_SA * sa = (T_SA*) malloc( sizeof( T_SA*));
    sa->states = (T_ENUM*) calloc(20, sizeof(T_ENUM));
    sa->events = (T_ENUM*) calloc(20, sizeof(T_ENUM));
	
	printf( "%d, %d", sa->states, sa->events);
	if(sa->states == NULL){
		printf("CALLOC FAILED -> STATES");
		exit(1);
	}
	
	if(sa->events == NULL){
		printf("CALLOC FAILED -> EVENTS");
		exit(1);
	}

    sa->state_cnt = 0;
    sa->event_cnt = 0;
    sa->index = sa_index++;
    sa->name = name;

    return sa;
}

void addState( T_SA * sa, char * name){
	printf("adding state...\n");

    int i = sa->state_cnt;
    T_ENUM* state = &sa->states[i];
    state->index = i;
    state->name = name;

    ++sa->state_cnt;
}

void addEvent( T_SA * sa, char * name){
	printf("adding event...%d\n", sa->event_cnt);

    int i = sa->event_cnt;
    T_ENUM* event = &sa->events[i];
    event->index = i;
    event->name = name;

    ++sa->event_cnt;
}

void freeSa( T_SA * sa){
	printf("freeing memory...");
	free( sa->states);
	free( sa->events);
	free( sa);
}

void printSa( T_SA * sa){
	printf("printing...\n");
    int i;
    printf( "sa: index = %d, name = %s, state_cnt = %d, evt_cnt = %d\n", sa->index, sa->name, sa->state_cnt, sa->event_cnt);

	if( sa->state_cnt > 0){
        printf( "states:\n");
        for( i = 0; i < sa->state_cnt; i++){
            T_ENUM * state = &sa->states[ i];
            printf( "\t%d -> %s\n", state->index, state->name);
        }
	}

	if( sa->event_cnt > 0){
        printf( "events:\n");
        for( i = 0; i < sa->event_cnt; i++){
            T_ENUM * evt = &sa->events[ i];
            printf( "\t%d -> %s\n", evt->index, evt->name);
        }
	}
}
