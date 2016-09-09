CC = g++
CFLAGS = -I/usr/X11R6/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/lib
LIBS = -lGLU -lGL -lglut -lXi -lXmu -lSOIL
PROG = driver
OBJS = $(PROG).o
$(PROG):	$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) *.cpp *.h $(LIBS)

