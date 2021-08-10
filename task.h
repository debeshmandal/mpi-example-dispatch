#ifndef _TASK_H
#define _TASK_H

#include <unistd.h>

namespace task {
  void nothing();
  void simulation(
    unsigned int timesteps, 
    unsigned int complexity, 
    int rank,
    unsigned int baseline_timestep = 100,
    bool verbose = false
  );
}

#endif // _TASK_H
