CC      ?= gcc
CFLAGS  ?= -O2 -Wall -Wextra -std=gnu99
LDFLAGS ?=
TARGET  := dumper
SRCS    := main.c
OBJS    := $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
