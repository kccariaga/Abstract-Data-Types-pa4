/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

/* minPQ.h T
    The purpose of this file is to declare function prototypes to be used
    in multiple files such as minPQ.c andg reedy04.c
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* ***************** Access functions */

/** isEmpty (Preconditions: PQ must have been created)
*/
int isEmptyPQ(MinPQ pq);

/** getMin (Precondition: PQ must have been created)
*/
int getMin(MinPQ pq);

/** getStatus (Precondition: PQ has been created)
*/
int getStatus(MinPQ pq, int id);

/** getParent (Precondition: PQ has been created)
*/
int getParent(MinPQ pq, int id);

/** getPriority (Precondition: PQ has been created)
*/
double getPriority(MinPQ pq, int id);


/* ***************** Manipulation procedures */

/** delMin ()
    deletes the minimum value in the queue
*/
void delMin(MinPQ pq);

/** insertPQ
    inserts values in queue
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);


/* ***************** Constructors */

/** createPQ
    Creates the priority queue by initializing arrays to values.
    status is set to UNSEEN until called.
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif
