CC = gcc
OBJ = src/main.o \
	  src/product/product.o \
	  src/invoice/invoice_line.o \
      src/invoice/invoice_line_list.o \
      src/invoice/invoice.o \
      src/move/move.o \
      src/move/move_line.o \
      src/printer/printer.o
BIN = erp

all: ${BIN}
	${CC} -o ${BIN} ${OBJ}

${BIN}: ${OBJ}

test:
	(cd test && make test)

clean:
	rm -rf ${BIN} ${OBJ}
	(cd test && make clean)


.PHONY: clean test
