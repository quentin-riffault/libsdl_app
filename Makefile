CC=g++
BUILD=./build
TEST=./lib
DEPLOY=/usr/lib

PHONY: test deploy clean uninstall


test: $(TEST) $(BUILD)/SDL_app.o
	$(CC) -shared -o $(TEST)/libsdl_app.so $^

deploy: $(DEPLOY) $(BUILD)/SDL_app.o
	$(CC) -shared -o $(DEPLOY)/libsdl_app.so $^

clean: 
	rm -f $(BUILD)/* 

uninstall:
	rm -f $(BUILD)/* $(TEST)/* $(DEPLOY)/libsdl_app.so

$(BUILD):
	mkdir -p $@

$(TEST):
	mkdir -p $@

$(DEPLOY):
	mkdir -p $@

$(BUILD)/SDL_app.o: $(BUILD) SDL_app.cpp
	$(CC) -c -fPIC -o $@ $^

