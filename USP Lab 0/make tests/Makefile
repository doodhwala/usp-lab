plscompule=gcc
program : a.o b.o c.o client.o
	$(plscompule) -o program a.o b.o c.o client.o
a.o : a.c
	$(plscompule) -c a.c
b.o : b.c
	$(plscompule) -c b.c
c.o : c.c
	$(plscompule) -c c.c
client.o : client.c
	$(plscompule) -c client.c
clean :
	rm -f program *.o *~
