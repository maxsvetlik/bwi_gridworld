#include "include/Agent.h"

#include "include/grid.h"
#include <sstream>

using namespace std;

namespace bwi_gridworld {
	bool up = false;
  	char Agent::nextAction(){
  		if(x == Grid::width)
  			return 'w';
  		if(y == Grid::height)
  			return 's';
  		if(x == 0)
  			return 'e';
  		if(y == 0)
  			return 'n';
  		return 's';
  	}
}
