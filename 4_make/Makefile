
SRCS= foo.c bar.c
CFLAGS= -g -Wall -pedantic
LOADLIBS= -L $(HOME)/adapilot/current/training/LinuxProgramDevelopment/4_make/
LDLIBS= myfuncs
TARGET= foobar

foobar_basic: foo.c foo.h bar.c
	gcc -o foobar.exe foo.c bar.c

$(TARGET)_cool: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(SRCS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.a
	rm -f *.so.*
