FILE= startup.c util.c caesar.c tools.c error.c freq.c permute.c vigenere_decoder.c
COMMAND = gcc 
INCLUDE = -I./tools
FLAGS = -Wall -g -O0

all: tools

tools: $(FILE)
	$(COMMAND) $(FLAGS) $(INCLUDE) $(FILE) -o tools

clean:
	rm -rf tools

