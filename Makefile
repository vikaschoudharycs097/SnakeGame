.PHONY: build
build:
	sudo apt-get install gcc  
	sudo apt-get install cmake
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-ttf-dev
	mkdir -p build
	cd build && \
	cmake .. && \
	make && \
	sudo make install
	sudo cp -R ./fonts /usr/local/bin/


.PHONY: clean
clean:
	rm -rf build
