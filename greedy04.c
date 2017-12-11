/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjWgtVec.h"
#include "loadWgtGraph.h"
#include "minPQ.h"


void updateFringe(MinPQ pq, AdjWgtVec* adjInfo, int v, int task){
    //AdjWgtVec * remAdj;
    //remAdj = adjInfo;
    int i = 1;
    // If Prim
    if (task == 1){


        while (i <= adjWgtSize(adjInfo[v])){
            AdjWgt wInfo = adjWgtData(adjInfo[v], i);
            int w = wInfo.to;
            double newWgt = wInfo.wgt;
            if(getStatus(pq, w) == UNSEEN){
                insertPQ(pq, w, newWgt, v);
            }
            else if(getStatus(pq, w) == FRINGE){
                if (newWgt < getPriority(pq, w)){
                    decreaseKey(pq, w, newWgt, v);
                }
            }
            i++;
        }
    }
    else{
        //Djikstra's
        double myDist = getPriority(pq, v);

        while (i <= adjWgtSize(adjInfo[v])){
            AdjWgt wInfo = adjWgtData(adjInfo[v], i);
            int w = wInfo.to;
            double newDist = myDist + wInfo.wgt;
            if(getStatus(pq, w) == UNSEEN){
                insertPQ(pq ,w, newDist, v);
            }
            else if(getStatus(pq,w) == FRINGE){
                if(newDist < getPriority(pq, w)){
                    decreaseKey(pq, w, newDist, v);
                }
            }
            i++;
        }
    }
}


void greedyTree(int n, AdjWgtVec* adjInfo, int* status, int* parent,
                double* fringeWgt, int task, int s)
{
    MinPQ pq = createPQ(n, status, fringeWgt, parent);

    insertPQ(pq, s, 0, -1);

    while(isEmptyPQ(pq) == 0){
        int v = getMin(pq);
        delMin(pq);
        updateFringe(pq, adjInfo, v, task);
    }
    free(pq);
}

void printOutput(int * status, int * parent, double* fringeWgt, int n,
                 int edgeCount, AdjWgtVec * adjInfo, int task, int s)
{
    printf("_______________________________________\nAdjList w/Weights\n\n");
    printf("Verticies= %d\nEdges= %d\n", n, edgeCount);
    printAdjVerts(adjInfo, n);

    printf("________________________________________\n");
    if (task == 1){
        printf("Prim's Algorithm\nStarting Vertex: %d\n",s);
    }
    if (task == 0){
        printf("Dijkstra's Algorithm\nStarting Vertex: %d\n", s);
    }
    printf("\nvertex\tstatus\t parent\t fringeWgt\t\n");
    for (int i = 1; i <=n; i++){
        printf("%d\t  %c\t %3d\t   %.2f\t\n",i, status[i], parent[i],
               fringeWgt[i]);

    }
}

int main(int argc, char * argv[]){
    int n; /*Number of nodes aka elements in the "array of intVecs" */
    int edgeCount;/*counts number of edges*/

    FILE *fp;
    char * fgetsRet;
    char line[1024];

     int task;// Determine whether -P or -D flag
     int s; //starting vertex

    if (argc == 4){
        fp = fopen(argv[3],"r");
        if (strcmp(argv[1],"-P") == 0){
            task = 1;
            printf("task -P passed\n");
        }
        if (strcmp(argv[1],"-D") == 0){
            task = 0;
            printf("task -D passed\n");
        }

        s = atoi(argv[2]);
        printf("Starting Vertex: %d\n", s);
    }

    fgetsRet = fgets(line, 1024,fp);
    sscanf(line, "%d", &n);//Get the number of nodes
    if (s > n || s <=0){
        printf("Invalid Starting Vertex..\n");
        fclose(fp);
        exit (1);
    }

    //Declarations
    AdjWgtVec * adjInfo = malloc((n+1) * sizeof(AdjWgtVec));
    int* status = calloc((n+1) ,sizeof(int));
    int* parent = calloc((n+1) , sizeof(int));
    double* fringeWgt = calloc((n+1) , sizeof(double));


    if (fp != NULL ) {
        /*Makes an array of empty vectors*/
        printf("File has been opened\n");
        for (int i= 1; i <= n; i++){
            adjInfo[i] = adjWgtMakeEmptyVec();
        }
        fgets(line,1024,fp);/*Read first line*/
        /*Read the rest of the file and assign values to edges*/
        edgeCount = pushEdges(fgetsRet, line, adjInfo, n, fp, task);
        fclose(fp);
    }
    else{
        fprintf(stderr, "No file Received\n");
        exit(1);
    }

    greedyTree(n, adjInfo,status, parent, fringeWgt, task, s);
    printOutput(status, parent, fringeWgt,n, edgeCount, adjInfo, task,s);

    //Free Memory
    freeAdjList(adjInfo, n);
    free(status);
    free(parent);
    free(fringeWgt);
    return 0;
}
