//BWI Patrolling gridworld project
#include <vector>
#include <stdio.h>
#include <iostream>
#include "include/grid.h"
#include "include/Agent.h"
#include <time.h>
#include <cstdlib>

Grid::Grid(std::vector<bwi_gridworld::Agent> const &ag){
	step_count = 0;
	found = false;
	int event_location[2];
	event_location[0] = -1;
	event_location[1] = -1;
	if(ag.size() == AGENTS){
		agents = ag;
		//initialized agents at their starting locations (currently the four corners of the grid)
		//TODO: Allow choice of where to start agents?
		initAgent(0, ag.at(0), 0, 0);
		initAgent(1, ag.at(1), width, 0);
		initAgent(2, ag.at(2), width, height);
		initAgent(3, ag.at(3), 0, height);
	}
  //printf("agent_positions[%d] = %x\n", 0, agent_positions[0]);
  Grid::eventInit();
  //printf("finished initializing grid\n");
}

bool Grid::validMove(int agent_id, char direction){
  printf("VALIDMOVE\n");
  printf("agent_positions[%d] = %x\n", agent_id, agent_positions[agent_id]);
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
  return 0;
  event_location[0] = random_x;
  event_location[1] = random_y;
  std::cout << "Event at location: " << random_x << ", " << random_y << std::endl;
  timer = time(0);
}
int Grid::initAgent(int index, bwi_gridworld::Agent ag, int x_pos, int y_pos){ //returns the agent_id
  Pos* p = new Pos(x_pos, y_pos);
  agent_positions[index] = p;
  printf("Agent (id: %d) initialized at position [%d, %d]\n", index, p->x, p->y);
  printf("agent_positions[%d] = %x\n",index, agent_positions[index]);
	return index;
}
void Grid::event_found(){
	found = true;
	double duration;
	duration = ((float)( time(0) - timer ));
	std::cout << "It took your agent(s) " << duration << " seconds to find the intruder!" << std::endl;
	std::cout << "It took your agent(s) " << step_count << " simulation steps to find the intruder!" << std::endl;
}
//Polls the agents for their next move
int Grid::next(){
  printf("NEXT\n");
  printf("agents.size() = %d\n", agents.size());
		for(int i = 0; i < AGENTS; i++){
			char agent_action = agents.at(i).nextAction();
      printf("agent_action: %c\n", agent_action);

			if(validMove(i, agent_action)){
				std::cout << "Made it!" << std::endl;
				step(i, agent_action);
				setPos(i);
				if(agent_positions[i]->x == event_location[0] && agent_positions[i]->y == event_location[1]){
					event_found();
					return 1;
				}	
			}
			else{ //Agent's move not valid
					//TODO: add some action to handle invalid moves
			}
		}
	step_count++;
	return 0;
}

void Grid::setPos(int agent_id){
	agents.at(agent_id).x = agent_positions[agent_id]->x;
	agents.at(agent_id).y = agent_positions[agent_id]->y;
}

const int Grid::getWidth(){return width;}
const int Grid::getHeight(){return height;}
const int Grid::getStep(){return step_count;}
