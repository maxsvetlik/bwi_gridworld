#include "grid/Agent.h"
#include <cstdlib>
#include "grid/grid.h"
#include <sstream>
#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

//Max's probabilistic agent - codename 007

using namespace std;

namespace bwi_gridworld {
  	char Agent::nextAction(){
  	int move = std::rand() % 4;
		// std::cout << "move: " << move << std::endl;
		switch(move) {
  			case 1 : return 'n'; break;
  			case 2 : return 's'; break;
  			case 3 : return 'e'; break;
  			case 4 : return 'w'; break;
  		}
	}
}
