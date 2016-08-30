
SRCS1= memover.c
SRCS2= memleak.c
CFLAGS= -g -Wall -pedantic -pg -lefence
TARGET1= memover
TARGET2= memleak

$(TARGET1): $(SRCS1)
	$(CC) $(CFLAGS) -o $(TARGET1).exe $(SRCS1)

$(TARGET2): $(SRCS2)
	$(CC) $(CFLAGS) -o $(TARGET2).exe $(SRCS2)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.a
	rm -f *.so.*
	rm -f *.out
