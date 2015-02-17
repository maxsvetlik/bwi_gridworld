#include "include/grid.h"
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
/*
* Driver file for the simulated GRID project.
* Here is where all agents will be assembled into a vector and passed into the created grid object.
*
*/

int main(int argc, char *argv[]){
	std::srand(time(0)); //seeds random number generator with the current time
	bwi_gridworld::Agent a0, a1, a2, a3;
	std::vector <bwi_gridworld::Agent> ag;
	ag.push_back(a0);
	ag.push_back(a1);
	ag.push_back(a2);
	ag.push_back(a3);
	Grid grid(ag);
	grid.runExperiments();
	return 0;
}
