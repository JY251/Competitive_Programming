TARGET=a
TARGET=b
TARGET=c
TARGET=d
TARGET=e
main:
	g++ -Wall -o a.out $(TARGET).cpp
a:
	g++ -Wall -o a a.cpp
b: 
	g++ -Wall -o b b.cpp
c:
	g++ -Wall -o c c.cpp
d:
	g++ -Wall -o d d.cpp
e:
	g++ -Wall -o e e.cpp
clean:
	rm -f a.out a b c d e f 3 4 5 6