all: main.c date.c ls.c mkdir.c rm.c cat.c
	gcc cat.c -o cat
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc date.c -o date
	gcc mkdir.c -o mkdir
	gcc main.c -o main
	./main