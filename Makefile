CC=clang
CFLAGS=-Wall
VPATH=utils
BUILDDIR=build
SRC=$(wildcard $(VPATH)/*.c)
MAIN=$(wildcard ./*.c)
OBJ=$(subst utils/,$(BUILDDIR)/, $(subst .c,.o, $(SRC))) $(subst ./,$(BUILDDIR)/, $(subst .c,.o, $(MAIN)))
BIN=bin
PROGRAM=walker
TARGET=$(BIN)/$(PROGRAM)

all: walker

$(BUILDDIR)/%.o: $(VPATH)/%.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $< -o $@

$(BUILDDIR)/%.o: %.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $< -o $@

walker: $(OBJ)
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

run:
	./$(TARGET)

clean:
	rm -fr $(BUILDDIR) $(BIN)
