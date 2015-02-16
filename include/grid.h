#include <vector>
#include <time.h>

class Grid{
        public:
		std::vector<std::vector<int> > agent_positions;
        const static int width = 10;
        const static int height = 10;
        int step_count;
        bool found;
        clock_t timer;
        int event_location[];
        Grid();
        bool validMove(int, char);
        int eventInit();
        int next(std::vector<char>);
        int step(int, char);
        int* getPos(int);
        void event_found();
        int initAgent(int, int);
};

