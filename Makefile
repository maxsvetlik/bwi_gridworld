all: grid

grid: grid.cpp
	g++ grid.cpp -o grid

clean:
	rm -rf grid
