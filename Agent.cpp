#include "include/Agent.h"
#include <cstdlib>
#include "include/grid.h"
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <iostream>


//Max's probabilistic agent - codename 007




using namespace std;

namespace bwi_gridworld {
  	char Agent::nextAction(){
  		//This is a bug. Needs better seed generation.
  		std::srand(time(0));
  		int random = std::rand();
  		std::srand(random);
  		int move = std::rand() % 4;
		std::cout << "Got " << move << std::endl;
		switch(move) {
  			case 1 : return 'n'; break;
  			case 2 : return 's'; break;
  			case 3 : return 'e'; break;
  			case 4 : return 'w'; break;
  		}
	}
}
