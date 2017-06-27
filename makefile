CC=gcc
OBJS= palavra.o red_black_tree.o leitura.o interface.o main.o

main:$(OBJS)
	$(CC) $(OBJS) -o Wordnator

red_black_tree.o:
	$(CC) -c src/red_black_tree.c

palavra.o:
	$(CC) -c src/palavra.c

leitura.o:
	$(CC) -c src/leitura.c

interface.o:
	$(CC) -c src/interface.c

main.o:
	$(CC) -c main.c
