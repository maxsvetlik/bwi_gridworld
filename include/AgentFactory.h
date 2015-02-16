#ifndef bwi_gridworld_AgentFactory_h__guard
#define bwi_gridworld_AgentFactory_h__guard

#include "Action.h"

#include <string>
#include <map>
#include <stdexcept>

namespace bwi_gridworld {

struct AgentFactory {
	
	typedef std::map<std::string, Action*> ActionMap;
	
	AgentFactory(Action *act);
	
	static Agent *byName(const std::string& name) throw (std::runtime_error);
	static AgentMap &actions();
	
	
	
	
};

}

#endif
