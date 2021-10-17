FILE= startup.c caesar.c tools.c error.c
COMMAND = gcc 
INCLUDE = -I./tools
FLAGS = -Wall -g -O0

all: tools

tools: $(FILE)
	$(COMMAND) $(FLAGS) $(INCLUDE) $(FILE) -o tools

clean:
	rm -rf tools

