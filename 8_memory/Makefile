
SRCS= foo_syscall.c 
CFLAGS= -g -Wall -pedantic
TARGET= foo_syscall

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(SRCS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.a
	rm -f *.so.*
