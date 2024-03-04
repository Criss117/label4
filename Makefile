CC = gcc
CFLAGS = -Wall -I./include

SRCDIR = src
OBJDIR = output

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $(OBJDIR)/$@
	rm -f $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(OBJDIR)/$(TARGET)