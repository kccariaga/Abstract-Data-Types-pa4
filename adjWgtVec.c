/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

#include "adjWgtVec.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct AdjWgtVecNode
{
    AdjWgt * data;
    int sz;
    int capacity;
}AdgWgtVec;


/*Constructor*/
/** adjWgtMakeEmptyVec()
 * preconditions: none.
 * postconditions: Let /return be the value returned by adjWgtMakeEmptyVec().
 *    Then adjWgtCapacity(/return) == 4, adjWgtSize(/return) == 0).
 */
AdjWgtVec adjWgtMakeEmptyVec(void){
    AdjWgtVec newVec;
    newVec = calloc(1, sizeof(struct AdjWgtVecNode));
    newVec->data = calloc(adjWgtInitCap, sizeof(AdjWgt));
    newVec->sz = 0;
    newVec->capacity = adjWgtInitCap;

    return newVec;
}

/* Access functions
 */
AdjWgt adjWgtTop(AdjWgtVec myVec){
    AdjWgt newTop;
    newTop = adjWgtData(myVec, myVec->sz);
    return newTop;
}

/** adjWgtData()
 * precondition: 0 <= i < adjWgtSize(myVec).
 */
AdjWgt adjWgtData(AdjWgtVec myVec, int i){
    return myVec->data[i];
}

/** adjWgtSize()
 * precondition: myVec has been constructed.
 */
int adjWgtSize(AdjWgtVec myVec){
    return myVec->sz;
}

/** adjWgtCapacity()
 * precondition: myVec has been constructed.
 */
int adjWgtCapacity(AdjWgtVec myVec){
    return myVec->capacity;
}

/** adjWgtVecPush()
 * precondition: myVec has been constructed.
 * postconditions: Let /sz/ = adjWgtSize(myVec) before the call.
 *                 Let /cap/ = adjWgtCapacity(myVec) before the call.
 *    Then after the call, adjWgtSize(myVec) == /sz/+1,
 *        and adjWgtTop(myVec) == newE and adjWgtData(myVec, /sz/) == newE.
 *    Also, for all 0 <= i < /sz/: adjWgtData(myVec, i) is unchanged.
 *    Also, if (/sz/+1) > /cap/, then after the call,
 *        adjWgtCapacity(myVec) = 2 * /cap/.
 *    otherwise, adjWgtCapacity(myVec) is unchanged.
 */
void adjWgtVecPush(AdjWgtVec myVec, AdjWgt newE){
    AdjWgt* newData;
    int newSz = adjWgtSize(myVec) + 1;
    myVec->sz = newSz;

    //if (sz + 1) > cap then double array capacity
    if( newSz >= (myVec->capacity)){
        myVec->capacity = 2 * myVec->capacity;
        newData = realloc(myVec->data, myVec->capacity * sizeof(AdjWgt));

        if( newData !=  myVec->data){
            myVec->data = newData;
        }
    }

    // append new value onto the vector
    myVec->data[myVec->sz]= newE;

    //printf("to: %d\t", newE.to);
    //printf("weight: %.2f\n\n", newE.wgt);
}

/** adjWgtVecPop()
 * precondition: myVec has been constructed and adjWgtSize(myVec) > 0.
 * postconditions: Let /sz/ = adjWgtSize(myVec) before the call.
 *                 Let /cap/ = adjWgtCapacity(myVec) before the call.
 *    Then after the call, adjWgtSize(myVec) == /sz/-1,
 *        adjWgtTop(myVec) == adjWgtData(/sz/-2).
 *    Also, for all 0 <= i < /sz/-1: adjWgtData(myVec, i) is unchanged.
 *    Also, adjWgtCapacity(myVec) is unchanged.
 */
void adjWgtVecPop(AdjWgtVec myVec){
    myVec->sz--;
}

void freeVector(AdjWgtVec myVec){
    free(myVec->data);
    free(myVec);
}


void freeAdjList (AdjWgtVec * adjList, int n){
    for(int i = 1; i <= n; i++){
        freeVector(adjList[i]);
    }
    free(adjList);
}


