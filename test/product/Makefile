CC = gcc
TEST = test_product
OBJ = test_product.o \
	../../src/product/product.o

all: test_product
	./${TEST}

test_product: ${OBJ}

clean:
	rm -rf ${OBJ} ${TEST}