TARGET = main

SRCS := $(shell find . -name '*.c')

HEADERS := $(shell find . -name '*.h')

OBJS := $(SRCS:.c=.o)

CC = gcc
#CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean