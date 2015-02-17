#include <vector>
#include <time.h>
#include "Agent.h"
#include <cstddef>

#define NUM_TESTS 10
#define MAX_STEPS 500
#define AGENTS 4

struct Pos{
  int x,y;
  Pos(int x, int y) : x(x), y(y){};
};

class Grid{
  private:
    int step_count;
    int eventsCreated;
    int eventsFound;
    clock_t timer;
    std::vector<Pos*> event_locations;
    Pos* agent_positions[AGENTS];
    void event_found();
    bool alreadyOccupied(int, int);
    void checkIfEventFound(int);
    int printResults();
    void setPos(int agent_id);
    int initAgent(int index, bwi_gridworld::Agent, int, int);
    std::vector<bwi_gridworld::Agent> agents;

  public:
    Grid(std::vector<bwi_gridworld::Agent> const &ag);
    const static int width = 10;
    const static int height = 10;
    bool running;
    bool validMove(int, char);
    int eventInit();
    const int getWidth();
    const int getHeight();
    const int getStep();
    void runExperiments();
    int next();
    int step(int, char);
    const int* getPos(int);
};

