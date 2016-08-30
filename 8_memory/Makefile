
SRCS= foo.c 
CFLAGS= -g 
TARGET= foo

SRCS2= bar.c
TARGET2=bar

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(SRCS)

$(TARGET2): $(SRCS2)
	$(CC) $(CFLAGS) -o $(TARGET2).exe $(SRCS2)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.a
	rm -f *.so.*
