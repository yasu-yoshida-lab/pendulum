# Makefile
CC = g++
CFLAGS = -g -Wall -std=c++17
OBJS = main.o
TARGET = main

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

ALL: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	./$(TARGET)

clean:
	rm -rfv $(OBJS) $(TARGET)
	rm -rfv *.txt
	rm -rfv *.png

.PHONY: clean
