CC = g++
CC_FLAGS = -std=c++17 -Wall -Werror -pedantic -Wshadow -Wunused-value

% : %.cpp
		${CC} ${CC_FLAGS} -o $@ $< 
		./$@

.PHONY: clean ra rb rc rd re rf

clean : 
	rm A B C D E F
ra :
	./A
rb :
	./B
rc :
	./C
rd :
	./D
re :
	./E
rf :
	./F