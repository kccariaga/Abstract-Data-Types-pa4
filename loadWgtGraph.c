/**
*    Karen Cariaga
*    kccariag
*    pa4
*/

#include "loadWgtGraph.h"
#include "adjWgtVec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Edge parseN(char line[], int nodes)
{
    Edge newE;
    int numFields;

    numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
    if (numFields < 2 || numFields > 3 || newE.from > nodes || newE.to > nodes )
    {
        printf("Bad edge\t(from) (to) (weight):\n\t\t %s \n\n", line);
        exit(1);
    }
    if (numFields == 2)
        newE.weight = 0.0;

    return newE;
}

int pushEdges(char * ret, char line[], AdjWgtVec  adjInfo[], int n, FILE * fp, int flag){
    int edgeCount = 0;
    char*fgetsRet = ret;
    AdjWgt temp;

    while (fgetsRet == line)
    {
        Edge e = parseN(line, n);
        edgeCount +=1;

        if(flag == 1){
            if (e.from != e.to){
                temp.to = e.to;
                temp.wgt = e.weight;
                adjWgtVecPush(adjInfo[e.from], temp);

                temp.to = e.from;
                adjWgtVecPush(adjInfo[e.to] ,temp);
                edgeCount +=1;
            }
        }
        else{
            temp.to = e.to;
            temp.wgt = e.weight;
            adjWgtVecPush(adjInfo[e.from], temp);

        }
        fgetsRet = fgets(line, 1024, fp);
    }

    return edgeCount;
}


void printAdjVerts(AdjWgtVec * adjInfo,int n){
 for(int i = 1; i<=n; i++){
        printf("%d\t",i);
        printVector(adjInfo[i]);
        printf("\n");
}
}


void printVector(AdjWgtVec myVec){
    AdjWgt top = adjWgtTop(myVec);
    AdjWgt data;

    if (top.to == 0){
        printf("null");
    }
    else{
        printf("[");
        for (int i = adjWgtSize(myVec); i != 0; i--){
            data = adjWgtData(myVec, i);
            printf(" ( %d | %.2f )", data.to, data.wgt);
            if(i > 1){
                printf(",");
            }
        }
        printf("]");
    }
}



