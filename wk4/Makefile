CC=clang
CFLAGS=-Wall -Werror

all : testSet adts

testSet : testSet.c Set.c Set.h
	$(CC) $(CFLAGS) -o testSet testSet.c Set.c

adts : adts.c Set.c Set.h
	$(CC) $(CFLAGS) -o adts adts.c Set.c