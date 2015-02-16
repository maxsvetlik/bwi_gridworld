# bwi_gridworld
Project for the FRI class in Autonomous Robot stream

Current status:
Weird issue where a grid.h couldn't see include/Agent.h but could see Agent.h in the main directory, so a copy of it lives there until it is sorted out. The two headers should stay identical.
Current forward declared complication error from Grid::next() function. Tried several workthroughs, nothing that worked. -Max

This project holds the codebase for the agent-gridworld simulation!

The premise is this: There is a width x height grid in which four agents are placed.
At some point during the simulation, an event will be placed on the map. The time it takes for the first agent to be found is measured.
It is adventageous to minimize this time, which can be accomplished with optimal policies for each agent.

The GRID simulation will poll each agent for their move on each simulation step. The 'brains' of the agent is in the return method of nextMove().
How the agent knows what to return and when is a matter of policy.
