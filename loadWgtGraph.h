/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjWgtVec.h"
#ifndef LOADWGTGRAPH_H_INCLUDED
#define LOADWGTGRAPH_H_INCLUDED


typedef struct {
    int from;
    int to;
    double weight;
} Edge;

/** precondition: A file must have been opened
*   postcondition: The file input is being stored onto the Edge struct as
*                  /to/ , /from/ , /weight/
*/
Edge parseN(char line [], int nodes);

/** precondition: File must have been opened with proper data
*   postcondition: Calls parse edge to store data into the struct
*                Then returns the edge count
*                if (flag == 0)
*                   temp.to = e.to;
                    temp.wgt = e.weight;
                    adjWgtVecPush(adjInfo[e.from], temp);
                else
                    temp.to = e.to;
                    temp.wgt = e.weight;
                    adjWgtVecPush(adjInfo[e.from], temp);

                    temp.to = e.from;
                    adjWgtVecPush(adjInfo[e.to] ,temp);
*
*
*/
int pushEdges(char * ret, char line[], AdjWgtVec  adjInfo[], int n, FILE * fp,
              int flag);

//Prints out adjacency list with weights
void printAdjVerts(AdjWgtVec * adjInfo,int n);

// is called by printAdjVerticies to output the contents of every vector
void printVector(AdjWgtVec myVec);

//Frees values in the adjacency list by calling free vector via a for loop
void freeAdjList (AdjWgtVec * adjList, int n);
void freeVector(AdjWgtVec myVec);

#endif

