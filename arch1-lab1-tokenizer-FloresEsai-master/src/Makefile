# List of object files
OBJS = history.o tokenizer.o
OBJS_MAIN = $(OBJS) uimain.o
OBJS_TEST = $(OBJS) tester.o

CFLAGS=-g -O3

# file dependencies
tokenizer.h: $(OBJS_MAIN)
history.h: $(OBJS_MAIN)

# user input
tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

all: tokenizer

clean:
	rm -f $(OBJS) $(OBJS_MAIN) $(OBJS_TEST) tokenizer tokenizer_test

run: tokenizer
	./tokenizer

test: tokenizer_test
	./tokenizer_test