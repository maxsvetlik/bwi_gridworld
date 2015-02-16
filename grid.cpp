//BWI Patrolling gridworld project
#include <vector>
#include <stdio.h>
#include <iostream>
#include "include/grid.h"
#include <time.h>
#include <cstdlib>

Grid::Grid(){
	step_count = 0;
	found = false;
	int event_location[2];
	event_location[0] = -1;
	event_location[1] = -1;
	eventInit();
}

bool Grid::validMove(int agent_id, char direction){
	if(agent_positions.size() >= agent_id){
		int agent_x = agent_positions.at(agent_id).at(0);
		int agent_y = agent_positions.at(agent_id).at(1);
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
			agent_positions.at(agent_id).at(1)++;
		if(direction == 'e')
			agent_positions.at(agent_id).at(0)++;
		if(direction == 's')
			agent_positions.at(agent_id).at(1)--;
		if(direction == 'w')
			agent_positions.at(agent_id).at(0)--;
		
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
    event_location[0] = random_x;
    event_location[1] = random_y;
    std::cout << "Event at location: " << random_x << ", " << random_y << std::endl;
    timer = time(0);
}
int Grid::initAgent(int x_pos, int y_pos){ //returns the agent_id
	std::vector<int> agent;
	agent.push_back(x_pos);
	agent.push_back(y_pos);
	agent_positions.push_back(agent);
	std::cout << "Agent initialized at position 0, 0" << std::endl;
	return agent_positions.size();
}
void Grid::event_found(){
	found = true;
	double duration;
	duration = ((float)( time(0) - timer ));
	std::cout << "It took your agent(s) " << duration << " seconds to find the intruder!" << std::endl;
	std::cout << "It took your agent(s) " << step_count << " simulation steps to find the intruder!" << std::endl;
}
int Grid::next(std::vector<char> moves){
	if(moves.size() < agent_positions.size()){
		std::cout << "Error: argument passed into next() smaller than number of initialized agents." << std::endl;
		return -1;
	}
	else{
		for(int i = 0; i < moves.size(); i++){
			step(i, moves[i]);
			if(agent_positions.at(i).at(0) == event_location[0] && agent_positions.at(i).at(1) == event_location[1]){
				event_found();
				return 1;
			}
		}
	}
	step_count++;
	return 0;
}
int* Grid::getPos(int agent_id){
	int coordinates[2];
	coordinates[0] = agent_positions.at(agent_id).at(0);
	coordinates[1] = agent_positions.at(agent_id).at(1);

	std::cout << "Agent 0 now at " << agent_positions.at(agent_id).at(0) << ", " << agent_positions.at(agent_id).at(1) << std::endl;
	return &coordinates[0];
}
int main(){
	Grid g1;
	g1.initAgent(0,0);
	char move = ' ';
	std::vector<char> moves;	
	while(move != 'q' && !g1.found){
		std::cout << ". for a single step. q to exit. coordinal directions for moves: ";
		std::cin >> move;
		std::cout << std::endl;
		if(move == 'n' || move == 's' || move == 'e' || move =='w'){
			moves.push_back(move);
			g1.next(moves);
			std::cout << "Agent 0 now at " << g1.agent_positions.at(0).at(0) << ", " << g1.agent_positions.at(0).at(1) << std::endl;		
		}
		moves.clear();
	}
		
}
