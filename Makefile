SRC := screens.c charset.c rdrand.o main.c
OUT := chargen

ASM := rdrand.S

LNK := $(shell pkg-config --cflags --libs ncurses) -z noexecstack
WRN := -Wall -Wextra
OPT := -march=native -O3

default:
	nasm -f elf64 $(ASM)
	$(CC) $(CFLAGS) $(WRN) $(OPT) -o $(OUT) $(SRC) $(LNK)
clean:
	rm -f chargen *.o

