#include <vector>
#include <time.h>

class Grid{
  private:
    int step_count;
    bool found;
    clock_t timer;
    int event_location[];
    std::vector<std::vector<int> > agent_positions;
    void event_found();
    int initAgent(int, int);
    
  public:
    Grid();
    const static int width = 10;
    const static int height = 10;
    bool validMove(int, char);
    int eventInit();
    int next(std::vector<char>);
    int step(int, char);
    int* getPos(int);
};

