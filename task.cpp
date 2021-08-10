#include "task.h"
#include <chrono>
#include <iostream>

namespace task {
  void nothing() {
      // placeholder
      int y = 1;
  }

  void simulation(
    unsigned int timesteps, 
    unsigned int complexity,
    int rank,
    unsigned int baseline_timestep,
    bool verbose
  ) {

    // get time now
    auto start = std::chrono::high_resolution_clock::now();

    // sleep for a given number of microseconds
    // that is weighted by the complexity
    for (int i = 0; i < timesteps; i++) {
      usleep(complexity * complexity * baseline_timestep);
    }

    // get time at the end
    auto end = std::chrono::high_resolution_clock::now();

    // get duration
    std::chrono::duration<double, std::milli> duration = end - start;

    // print status message
    if (verbose) {
      printf(
        "Ran simulation[t=%d, c=%d] on rank %d for %f milliseconds!\n",
        timesteps, complexity, rank, duration.count()
      );
    }
  }
}
