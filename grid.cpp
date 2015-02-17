//BWI Patrolling gridworld project
#include <vector>
#include <stdio.h>
#include <iostream>
#include "include/grid.h"
#include "include/Agent.h"
#include <time.h>
#include <cstdlib>
/*
TODO: Add verbose mode?
Add in automated testing

GRID class
Creates a 2D grit, initializes agents in the map. At some point an event is placed on the map and the time is recorded from when the event is placed and an agent find's it.


*/


Grid::Grid(std::vector<bwi_gridworld::Agent> const &ag){
	step_count = 0;
	running = true;
	if(ag.size() == AGENTS){
		agents = ag;
		//initialized agents at their starting locations (currently the four corners of the grid)
		//TODO: Allow choice of where to start agents?
		initAgent(0, ag.at(0), 0, 0);
		initAgent(1, ag.at(1), width, 0);
		initAgent(2, ag.at(2), width, height);
		initAgent(3, ag.at(3), 0, height);
	}
}

bool Grid::validMove(int agent_id, char direction){
  	//printf("agent_positions[%d] = %x\n", agent_id, agent_positions[agent_id]);
  	printf("direct: %c\n", direction);
	if(agent_id < AGENTS){
    int agent_x = agent_positions[agent_id]->x;
    int agent_y = agent_positions[agent_id]->y;
		if(direction == 's' && ((agent_y - 1) < 0))
			return false;
		else if(direction == 'e' && ((agent_x) + 1 >= width))
			return false;
		else if(direction == 'n' && ((agent_y + 1) >= height))
			return false;
		else if(direction == 'w' && ((agent_x - 1) < 0))
			return false;
		else
			return true;
	}
	return false;
}
int Grid::step(int agent_id, char direction){
	if(validMove(agent_id, direction)){
		if(direction == 'n')
      agent_positions[agent_id]->y++;
		if(direction == 'e')
      agent_positions[agent_id]->x++;
		if(direction == 's')
      agent_positions[agent_id]->y--;
		if(direction == 'w')
      agent_positions[agent_id]->x--;
		
	}
	else 
		std::cout << "Invalid movement! " << std::endl;
}
//probablistically generates events and places them on the grid
int Grid::eventInit(){
	std::srand(time(0)); // use current time as seed for random generator
	if(std::rand() % 200 == 1){
	  int random_x = std::rand() % width;
	  int random_y = std::rand() % height;
	  Pos* p = new Pos(random_x, random_y);
	  event_locations.push_back(p);
	  eventsCreated++;
	  std::cout << "Event at location: " << random_x << ", " << random_y << std::endl;
	}
}
int Grid::initAgent(int index, bwi_gridworld::Agent ag, int x_pos, int y_pos){ //returns the agent_id
  Pos* p = new Pos(x_pos, y_pos);
  agent_positions[index] = p;
  //printf("Agent (id: %d) initialized at position [%d, %d]\n", index, p->x, p->y);
  //printf("agent_positions[%d] = %x\n",index, agent_positions[index]);
	return index;
}
int Grid::printResults(){
	std::cout << "Number of intruders found in this experiment: " << eventsFound << "." << std::endl;
	return eventsFound;
}
void Grid::checkIfEventFound(int agent_id){
	for(int i = 0; i < event_locations.size(); i++){
		if(agent_positions[i]->x == event_locations.at(i)->x && agent_positions[i]->y == event_locations.at(i)->y){
			eventsFound++;
			//removes the event from the event vector
			event_locations.erase(event_locations.begin() + i, event_locations.begin() + i + 1);
		}	
	}
}

//Polls the agents for their next move
int Grid::next(){
	eventInit();
	//First, check if the round over
	if(step_count >= MAX_STEPS){
		running = false;
		return 1;
	}
	if(running){
		for(int i = 0; i < AGENTS; i++){
			char agent_action = agents.at(i).nextAction();
			if(validMove(i, agent_action)){
				step(i, agent_action);
				setPos(i);
				checkIfEventFound(i);
			}
			else{ //Agent's move not valid
					//printf("Agent %d tried an invalid move!\n", i);
			}
		}
		step_count++;
	}
	return 0;
}
void Grid::runExperiments(){
	for(int i = 0; i < NUM_TESTS; i++){
		while(next() == 0){}
		step_count = 0;
		running = true;
		//initialized agents at their starting locations (currently the four corners of the grid)
		//TODO: Allow choice of where to start agents?
		initAgent(0, agents.at(0), 0, 0);
		initAgent(1, agents.at(1), width, 0);
		initAgent(2, agents.at(2), width, height);
		initAgent(3, agents.at(3), 0, height);
	}
	std::cout << "The experiments are over. Your agents found " << eventsFound << " events, out of " << eventsCreated << "." << std::endl;
}
//Method to set the position of the current agent in the agent's variable space.
//Note that if an Agent changes its own x,y variables, it does not change their position.
void Grid::setPos(int agent_id){
	agents.at(agent_id).x = agent_positions[agent_id]->x;
	agents.at(agent_id).y = agent_positions[agent_id]->y;
}

//methods to return information to Agents
const int Grid::getWidth(){return width;}
const int Grid::getHeight(){return height;}
const int Grid::getStep(){return step_count;}
