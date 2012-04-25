program_NAME := rtcwstats
program_SRCS := $(wildcard *.c)
program_SRCS_OBJS := src/${program_SRCS:.c=.o}
program_OBJS := src/$(program_SRCS_OBJS)
program_INC_DIRS := /usr/local/include
program_LIB_DIRS := /usr/local/lib
program_LIBS := mongoc

CFLAGS += -g -Wall $(foreach includedir, $(program_INC_DIRS), -I$(includedir))
LDFLAGS += $(foreach librarydir, $(program_LIB_DIRS), -L$(librarydir))
LDFLAGS += $(foreach library, $(program_LIBS), -l$(library))

.PHONY: all clean distclean

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean

