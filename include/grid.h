#include <vector>
#include <time.h>
#include "Agent.h"
#include <cstddef>

class Grid{
  private:
    int step_count;
    clock_t timer;
    int event_location[];
    std::vector<std::vector<int> > agent_positions;
    void event_found();
    int initAgent(bwi_gridworld::Agent, int, int);
    std::vector<bwi_gridworld::Agent> agents;
  public:
    Grid(std::vector<bwi_gridworld::Agent>);
    const static int width = 10;
    const static int height = 10;
    bool found;
    bool validMove(int, char);
    int eventInit();
    int getWidth();
    int getHeight();
    int getStep();
    int next();
    int step(int, char);
    int* getPos(int);
};

