# Makefile
CC = g++
CFLAGS = -g -Wall -std=c++17
OBJS = main.o
TARGET = main

default:
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
	./$(TARGET)
	python3 plot.py

clean:
	rm -rfv $(OBJS) $(TARGET)
	rm -rfv *.txt
	rm -rfv *.png

.PHONY: clean
