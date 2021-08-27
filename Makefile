CC=g++
BUILD=./build
TEST=./lib
DEPLOY=/usr/lib

PHONY: test deploy

$(BUILD)/SDL_app.o: SDL_app.cpp
	$(CC) -c -fPIC -o $@ $^

test: $(BUILD)/SDL_app.o
	$(CC) -shared -o $(TEST)/libsdl_app.so $^

deploy: $(BUILD)/SDL_app.o
	$(CC) -shared -o $(DEPLOY)/libsdl_app.so $^