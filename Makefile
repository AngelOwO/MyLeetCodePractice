# define not file actions.
.PHONY: all clean

all: main.o aaa

Concurrent_basic.o: Concurrent_basic.cpp header/Concurrent_basic.h
	clang++ --std=c++17 -pthread -include header/Concurrent_basic.h -c Concurrent_basic.cpp

main.o: main.cpp
	clang++ --std=c++17 -pthread -include header/Concurrent_basic.h -c main.cpp

aaa: main.o Concurrent_basic.o
	clang++ --std=c++17 -pthread main.o Concurrent_basic.o -o aaa

clean:
	rm main.o Concurrent_basic.o aaa