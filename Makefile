SRC := screens.c charset.c rdseed.o main.c
OUT := chargen

ASM := rdseed.S

LNK := $(shell pkg-config --cflags --libs ncurses) -z noexecstack
WRN := -Wall -Wextra
OPT := -march=native -O3

default:
	nasm -f elf64 rdseed.S
	$(CC) $(CFLAGS) $(WRN) $(OPT) -o $(OUT) $(SRC) $(LNK)
clean:
	rm -f chargen *.o

