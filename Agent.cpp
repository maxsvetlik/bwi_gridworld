#include "include/Agent.h"
#include "include/grid.h"
#include <sstream>

using namespace std;

namespace bwi_gridworld {
	bool up = false;
  	char Agent::nextAction(){
  		if(*Grid::getPos(0) == Grid::width)
  			return 'w';
  		if(Grid::getPos(0)[1] == Grid::height)
  			return 's';
  		if(Grid::width == 0)
  			return 'e';
  		if(Grid::height == 0)
  			return 'n';
  	}

  //Agent* clone(int id){}


}
