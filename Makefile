CC = gcc
CFLAGS = -Wall -Werror -std=c11

MAIN_FILES = main.c
ADT_FILES = $(wildcard ADT/**/*.c)

OBJ_FILES = $(ADT_FILES:.c=.o)

INCLUDES = $(addprefix -I, $(dir ${wildcard ADT/*/}))

all: ${OBJ_FILES}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDES }-c -o $@ $<

# todo: test
# test:

main: $(ADT_FILES)
	${CC} ${CFLAGS} ${INCLUDES} -o tubesalstrukdat $(filter-out %_driver.c,$(ADT_FILES)) main.c

clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean test
