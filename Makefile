all: grid

grid: grid.cpp Agent.cpp run_sim.cpp
	g++ Agent.cpp run_sim.cpp grid.cpp -o run_sim

debug: grid.cpp Agent.cpp run_sim.cpp
	g++ Agent.cpp run_sim.cpp grid.cpp -g -o run_sim

run:
	./run_sim

clean:
	rm -rf grid run_sim
