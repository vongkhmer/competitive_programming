CC = g++
FLAGS = -pedantic -std=c++17 -Wall -Wextra -Wshadow -Wunused-value

lib_test: lib_test.cpp number_theory.cpp modular_operation.cpp combinatorial.cpp
	${CC} ${FLAGS} -o $@ $<

.PHONY: r

r:
	./lib_test
