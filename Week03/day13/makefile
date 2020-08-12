ex01 : ex01.c
	gcc -o $@ $^
ex02 : ex02.c
	gcc -o $@ $^
ex03 : ex03.c
	gcc -o $@ $^
ex04 : ex04.c
	gcc -o $@ $& -D __DEBUG__
ex05 : ex05.c
	gcc -o $@ $^
ex06 : ex06.c ../../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ex07 : ex07.c ../../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ex08 : ex08.c ../../engine/button.c ../../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ex09 : ex09.c ../../engine/button.c ../../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ex08-2 : ex08-2.c button.c util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
pt1 : pt1.c
	gcc -o $@ $^