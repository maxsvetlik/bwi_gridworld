#include "include/Agent.h"
#include <cstdlib>
#include "include/grid.h"
#include <sstream>
#include <sys/time.h>
#include <stdio.h>
#include <iostream>

//Max's probabilistic agent - codename 007

using namespace std;

namespace bwi_gridworld {
  	char Agent::nextAction(){
  		//bug due to instantiation of objects all at once
  		struct timeval time; 
     	gettimeofday(&time,NULL);
     	sleep(.01);
	     // microsecond has 1 000 000
	     // Assuming you did not need quite that accuracy
	     // Also do not assume the system clock has that accuracy.
	     std::srand((unsigned)(time.tv_sec * 1000) + (time.tv_usec / 1000));
  		int move = std::rand() % 4;
		//std::cout << "move: " << move << std::endl;
		switch(move) {
  			case 1 : return 'n'; break;
  			case 2 : return 's'; break;
  			case 3 : return 'e'; break;
  			case 4 : return 'w'; break;
  		}
	}
}
