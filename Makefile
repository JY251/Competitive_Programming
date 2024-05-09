TARGET=a
TARGET=b
TARGET=c
TARGET=d
TARGET=e
main:
	g++ -Wall -o a.out $(TARGET).cpp
clean:
	rm -f a.out