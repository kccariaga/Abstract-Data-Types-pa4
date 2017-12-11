/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minPQ.h"
#define float_positiveInfinity 999999999999.9

struct MinPQNode{
    int numVerticies, numPQ;
    int minVertex;
    double oo;
    int* status;
    int* parent;
    double* fringeWgt;

}MinPQNode;

MinPQ createPQ(int n, int status[], double priority[], int parent[]){
    MinPQ pq = malloc((n+1) * sizeof(MinPQNode));
    pq->parent = parent;
    pq->fringeWgt = priority;
    pq->status = status;
    for (int i = 1; i <=n; i++){
        status[i] = UNSEEN;
    }
    pq->numVerticies = n;
    pq->numPQ = 0;
    pq->minVertex = -1;
    pq->oo = float_positiveInfinity;

    return pq;
}


/* ***************** Access functions */

/** isEmpty (what are the preconditions, if any? Replace this question with your comments.)
*/
int isEmptyPQ(MinPQ pq){
    return pq->numPQ == 0;
}

void findMin(MinPQ pq){
    double minWgt = pq->oo;
    for(int v = 1; v <= pq->numVerticies; v++){
        if(pq->status[v] == FRINGE){
            if(pq->fringeWgt[v] < minWgt){
                pq->minVertex = v;
                minWgt = pq->fringeWgt[v];
            }
        }
    }
}
/** getMin (what are the preconditions, if any? Replace this question with your comments.)
*/
int getMin(MinPQ pq){
    if (pq->minVertex == -1){
        findMin(pq);
    }
    return pq->minVertex;
}

/** getStatus (what are the preconditions, if any? Replace this question with your comments.)
*/
int getStatus(MinPQ pq, int id){
    return pq->status[id];
}

/** getParent (what are the preconditions, if any? Replace this question with your comments.)
*/
int getParent(MinPQ pq, int id){
    return pq->parent[id];
}

/** getPriority (what are the preconditions, if any? Replace this question with your comments.)
*/
double getPriority(MinPQ pq, int id){
    return pq->fringeWgt[id];
}


/* ***************** Manipulation procedures******************************* */

/** delMin (what are the preconditions and/or postconditions? Replace this question with your comment.)
*/
void delMin(MinPQ pq){
    int oldMin = getMin(pq);

    pq->status[oldMin] = INTREE;
    pq->minVertex = -1;
    pq->numPQ--;
}

/** insertPQ (what are the preconditions and/or postconditions? Replace this question with your comment.)
*/
void insertPQ(MinPQ pq, int id, double priority, int par){
    pq->parent[id] = par;
    pq->fringeWgt[id] = priority;
    pq->status[id] = FRINGE;
    pq->minVertex = -1;
    pq->numPQ++;

}

/** decreaseKey (what are the preconditions and/or postconditions? Replace this question with your comment.)
*/
void decreaseKey(MinPQ pq, int id, double priority, int par){
    pq->parent[id] = par;
    pq->fringeWgt[id] = priority;
    pq->minVertex = -1;
}
