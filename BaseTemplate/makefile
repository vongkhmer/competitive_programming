CC = g++
CC_FLAGS = -std=c++17 -Wall -Wextra -Wshadow -Wunused-value
INPUT_FILE = input.txt

main : main.cpp
	${CC} -o $@ ${CC_FLAGS} $<
	./$@ 

.PHONY: a, b, c, d,e, f, r 

a:
	mkdir -p solved && cp main.cpp solved/A.cpp 
b:
	mkdir -p solved && cp main.cpp solved/B.cpp
c:
	mkdir -p solved && cp main.cpp solved/C.cpp
d: 
	mkdir -p solved && cp main.cpp solved/D.cpp

e :
	mkdir -p solved && cp main.cpp solved/E.cpp

f : 
	mkdir -p solved && cp main.cpp solved/F.cpp
r :
	./main
