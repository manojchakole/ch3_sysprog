all : unix
unix : rdwrexe
rdwrexe : filemethods.o
	gcc -o rdwrexe filemethods.o
filemethods.o : filemethods.c
	gcc -c filemethods.c
