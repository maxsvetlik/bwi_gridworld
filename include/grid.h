#include <vector>
#include <time.h>
#include "Agent.h"
#include <cstddef>
#define AGENT_NUM 4

#define AGENTS 4

struct Pos{
  int x,y;
  Pos(int x, int y) : x(x), y(y){};
};

class Grid{
  private:
    int step_count;
    clock_t timer;
    //int event_location[];
    Pos* event_location;
    Pos* agent_positions[AGENTS];
    void event_found();
    void setPos(int agent_id);
    int initAgent(int index, bwi_gridworld::Agent, int, int);
    std::vector<bwi_gridworld::Agent> agents;

  public:
    Grid(std::vector<bwi_gridworld::Agent> const &ag);
    const static int width = 10;
    const static int height = 10;
    bool found;
    bool validMove(int, char);
    int eventInit();
    const int getWidth();
    const int getHeight();
    const int getStep();
    int next();
    int step(int, char);
    const int* getPos(int);
};

