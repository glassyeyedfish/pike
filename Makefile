CC = cc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
# LDFLAGS =

TGT = pike

SRC = $(shell find -type f -name "*.c")
OBJ = $(SRC:./src/%.c=./build/%.o)

SRC_DIR =  $(shell find src -type d)
OBJ_DIR = $(SRC_DIR:src/%=build/%)
BLD_DIR = ./build

all: ${BLD_DIR} ${OBJ_DIR} ${TGT}

${BLD_DIR}:
	mkdir -p $@

${OBJ_DIR}:
	mkdir -p $@

build/%.o: src/%.c
		${CC} -c ${CFLAGS} $< -o $@

${TGT}: ${OBJ}
		${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
		rm -fr build/
		rm ${TGT}