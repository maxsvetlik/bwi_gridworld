#include "include/Agent.h"
#include <cstdlib>
#include "include/grid.h"
#include <sstream>
#include <time.h>


//Max's probabilistic agent - codename 007




using namespace std;

namespace bwi_gridworld {
  	char Agent::nextAction(){
  		std::srand(time(0)); // use current time as seed for random generator
		int move = std::rand() % 4;

		switch(move) {
  			case 1 : return 'n';
  			case 2 : return 's';
  			case 3 : return 'e';
  			case 4 : return 'w';
  		}
	}
}
