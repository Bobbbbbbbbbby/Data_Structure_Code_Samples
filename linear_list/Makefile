CC = g++
SOURCE = main_test.cpp array_list.cpp
OUT_NAME = exe
DBG = -g
ARRAY = -D_ARRAY_
.PHONY:clean

all: array_dbg

array:
	$(CC) $(SOURCE) -o $(OUT_NAME) $(ARRAY)

array_dbg:
	$(CC) $(SOURCE) -o $(OUT_NAME) $(ARRAY) $(DBG)

clean:
	rm exe