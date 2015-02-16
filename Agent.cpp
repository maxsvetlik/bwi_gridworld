#include "include/Agent.h"
#include <sstream>

using namespace std;

namespace bwi_gridworld {
	bool up = false;
  	char nextAction(){
  		if(up)
  			return 'n';
  		return 's';
  	}

  //Agent* clone(int id){}


}
