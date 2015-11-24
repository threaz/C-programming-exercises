CFLAGS = -Wall -Iinc

sort_string_num: obj obj/alloc.o obj/Getline.o obj/lines.o obj/numcmp.o \
			obj/quicksort.o obj/rev_strcmp.o obj/main.o
	gcc ${CFLAGS} -o sort_string_num obj/alloc.o obj/Getline.o obj/lines.o \
			obj/numcmp.o obj/quicksort.o obj/rev_strcmp.o obj/main.o

obj:
	mkdir obj

obj/main.o: src/main.c 
	gcc -c ${CFLAGS} -o obj/main.o src/main.c

obj/alloc.o: inc/alloc.h src/alloc.c 
	gcc -c ${CFLAGS} -o obj/alloc.o src/alloc.c

obj/Getline.o: src/Getline.c inc/Getline.h
	gcc -c ${CFLAGS} -o obj/Getline.o src/Getline.c

obj/lines.o: src/lines.c inc/lines.h
	gcc -c ${CFLAGS} -o obj/lines.o src/lines.c

obj/numcmp.o: src/numcmp.c inc/numcmp.h
	gcc -c ${CFLAGS} -o obj/numcmp.o src/numcmp.c

obj/rev_strcmp.o: src/rev_strcmp.c inc/rev_strcmp.h
	gcc -c ${CFLAGS} -o obj/rev_strcmp.o src/rev_strcmp.c

obj/quicksort.o: src/quicksort.c inc/quicksort.h
	gcc -c ${CFLAGS} -o obj/quicksort.o src/quicksort.c

clean:
	rm -f obj/*
