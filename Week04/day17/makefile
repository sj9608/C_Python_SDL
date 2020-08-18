all : ex01 ex01_run

create : create.c
	gcc -o $@ $^
q1 : q1.c 
	gcc -o $@ $^ -g
q1ans : q1ans.c
	gcc -o $@ $^
q1ans2 : q1ans2.c
	gcc -o $@ $^
ex01 : ex01.c
	gcc -o ../../out/$@ $^
ex01_run :
	ex01.exe
ex01-1 : ex01-1.c
	gcc -o $@ $^
ex02 : ex02.c ../../engine/core.c
	gcc -g -o ../../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
ex02-2 : ex02-2.c ../../engine/core.c
	gcc -g -o ../../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
ex02-3 : ex02-3.c ../../engine/core.c
	gcc -g -o ../../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf