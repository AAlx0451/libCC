SRCS = $(wildcard *.c)
PREFIX ?= /usr/local

munch: $(SRCS)
	@printf "\tCC\t$^\n"
	@$(CC) $(CFLAGS) $^ -o $@

install: munch
	@printf "\tINSTALL\n"
	@install -m 775 $^ $(PREFIX)/bin

clean:
	@printf "\tCLEAN\n"
	@rm -rf munch

uninstall:
	@printf "\tUNINSTALL\n"
	@rm -rf $(PREFIX)/bin/munch
