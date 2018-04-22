OBJS = show_hello.cpp

CC = g++
COMPLIER_FLAGS =

LINKER_FLAGS = -I../include -L../lib -lSDL2 -Wl,-rpath=/usr/local/lib

TARGET = show_hello

all:$(OBJS)
	$(CC) $(OBJS) $(COMPLIER_FLAGS) $(LINKER_FLAGS) -o $(TARGET)

.PHONY: clean
clean:
	@rm -rf $(TARGET)
