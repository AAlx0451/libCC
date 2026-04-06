CPP      := cpp
CFRONT   := cfront
CC       := cc
AR       := ar
RANLIB   := ranlib

CPPFLAGS := -nostdinc -I../include -I../include/CC -U__cplusplus -D__cplusplus=1
CFLAGS   := -x c -c -w -Wno-return-type

OBJDIR   := objs
SRCS     := $(wildcard pure/*.C)
OBJS     := $(patsubst %.C, $(OBJDIR)/%.o, $(SRCS))

NAME     := libC.a

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\tAR\t$@\n"
	@$(AR) rc $@ $(OBJS)
	@$(RANLIB) $@

$(OBJDIR)/%.o: %.C
	@mkdir -p $(@D)
	@printf "\tC++\t$<\n"
	@$(CPP) $< $(CPPFLAGS) | $(CFRONT) | $(CC) $(CFLAGS) - -o $@

clean:
	@printf "\tCLEAN\n"
	@rm -rf $(OBJDIR) $(NAME)
