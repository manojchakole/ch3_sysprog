all:unix
unix:dupexe
dupexe:customdup2.o dupfunction.o
	gcc -o dupexe customdup2.o dupfunction.o
customdup2.o:customdup2.c
	gcc -c customdup2.c
dupfunction.o:dupfunction.c
	gcc -c dupfunction.c
