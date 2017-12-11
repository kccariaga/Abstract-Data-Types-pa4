#Karen Cariaga
#CruzID: kccariag
#pa4 makefile


CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE


greedy04:	greedy04.o loadWgtGraph.o  adjWgtVec.o  minPQ.o
	${CC}  -o greedy04  ${CFLAGS} greedy04.o  loadWgtGraph.o  adjWgtVec.o  minPQ.o

greedy04.o:	greedy04.c  loadWgtGraph.h  adjWgtVec.h
	${CC}  -c ${CFLAGS} greedy04.c

loadWgtGraph.o:	loadWgtGraph.c  loadWgtGraph.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c

adjWgtVec.o: adjWgtVec.c  adjWgtVec.h
	${CC}  -c  ${CFLAGS}  adjWgtVec.c

minPQ.o: minPQ.c  minPQ.h
	${CC}  -c  ${CFLAGS}  minPQ.c

clean:
	rm -f *.o
	rm -f "greedy04"