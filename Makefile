all: grid

grid: grid.cpp
	g++ Agent.cpp run_sim.cpp grid.cpp -o run_sim

clean:
	rm -rf grid