.PHONY:clean

CC=g++
CXX=g++
INCLUDE=-I/usr/local/include/CUnit
LIB_PATH=-L/usr/local/lib -L.
LIB=-lcunit -lmymath -lgmock -pthread -ldl

CFLAGS=-g -Wl,--no-as-needed

#DFLAGS=-DCUNIT_CONSOLE
DFLAGS=-DCUNIT_AUTOMATED

#SRC=$(wildcard *.c)
MATH_SRC=math.c
MATH_OBJ=$(MATH_SRC:%.c=%.o)
LIB_MATH=libmymath.so

UT_SRC=math_test.c main.c
UT_OBJ=$(UT_SRC:%.c=%.o)

UT_NAME=ut_test

all: $(UT_OBJ) $(LIB_MATH)
	$(CC) $(UT_OBJ) -o $(UT_NAME) $(LIB_PATH) $(LIB)

$(LIB_MATH): $(MATH_OBJ)
	$(CC) -shared $(MATH_OBJ) -o $(LIB_MATH)
	
$(MATH_OBJ):$(MATH_SRC)
	$(CC) -fPIC $(CFLAGS) -c $^

math_test.o:math_test.c
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $^

main.o:main.c
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $^
	
clean:
	-rm -rf $(UT_OBJ) $(MATH_OBJ) $(LIB_MATH) $(UT_NAME) 
