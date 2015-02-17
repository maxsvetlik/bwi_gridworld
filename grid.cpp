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
Add in functionality to print agent's metrics & performance
Add in automated testing

GRID class
Creates a 2D grit, initializes agents in the map. At some point an event is placed on the map and the time is recorded from when the event is placed and an agent find's it.


*/


Grid::Grid(std::vector<bwi_gridworld::Agent> const &ag){
	step_count = 0;
	found = false;
	timedOut = false;
	Pos* p = new Pos(-1, -1);
	event_location = p;
	if(ag.size() == AGENTS){
		agents = ag;
		//initialized agents at their starting locations (currently the four corners of the grid)
		//TODO: Allow choice of where to start agents?
		initAgent(0, ag.at(0), 0, 0);
		initAgent(1, ag.at(1), width, 0);
		initAgent(2, ag.at(2), width, height);
		initAgent(3, ag.at(3), 0, height);
	}
  Grid::eventInit();
}

bool Grid::validMove(int agent_id, char direction){
  	//printf("agent_positions[%d] = %x\n", agent_id, agent_positions[agent_id]);
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
//starts an event, places it at a random position
//starts the timer
int Grid::eventInit(){
	std::srand(time(0)); // use current time as seed for random generator
  int random_x = std::rand() % width;
  int random_y = std::rand() % height;
  Pos* p = new Pos(random_x, random_y);
  event_location = p;
  std::cout << "Event at location: " << random_x << ", " << random_y << std::endl;
  timer = time(0);
}
int Grid::initAgent(int index, bwi_gridworld::Agent ag, int x_pos, int y_pos){ //returns the agent_id
  Pos* p = new Pos(x_pos, y_pos);
  agent_positions[index] = p;
  printf("Agent (id: %d) initialized at position [%d, %d]\n", index, p->x, p->y);
  //printf("agent_positions[%d] = %x\n",index, agent_positions[index]);
	return index;
}
//Determines the metrics for the agent's performance
void Grid::event_found(){
	found = true;
	double duration;
	duration = ((float)( time(0) - timer ));
	std::cout << "It took your agent(s) " << duration << " seconds to find the intruder!" << std::endl;
	std::cout << "It took your agent(s) " << step_count << " simulation steps to find the intruder!" << std::endl;
}
//Polls the agents for their next move
int Grid::next(){
	//First, check if the agents have timed out.
	if(double duration = ((float)( time(0) - timer )) > TIME_OUT_TIME){
		printf("The agents took too long to find the event. Searching timed out. The experiment is over.");
		timedOut = true;
		return 0;
	}
		for(int i = 0; i < AGENTS; i++){
			char agent_action = agents.at(i).nextAction();
     		//printf("agent_action: %c\n", agent_action);

			if(validMove(i, agent_action)){
				step(i, agent_action);
				setPos(i);
				if(agent_positions[i]->x == event_location->x && agent_positions[i]->y == event_location->y){
					event_found();
					return 1;
				}	
			}
			else{ //Agent's move not valid
					printf("Agent %d tried an invalid move!\n", i);
			}
		}
	step_count++;
	return 0;
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
