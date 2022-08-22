all: clean
	mkdir build
	g++ -W src/maji.cpp -o build/maji
	cp -f build/maji.exe maji.exe

clean:
	rm -rf build/
