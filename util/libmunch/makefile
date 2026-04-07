SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

CC ?= cc
CFLAGS += -O3 -c

%.o: %.c
	@printf "\tCC\t$^\n"
	@$(CC) $^ $(CFLAGS) -o $@

libmunch.a: $(OBJS)
	@printf "\tAR\t$@\n"
	@ar rc $@ $^
	@ranlib $@

clean:
	@printf "\tCLEAN\n"
	@rm -f $(OBJS) libmunch.a
