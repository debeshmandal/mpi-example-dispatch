#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <bits/stdc++.h>
#include <chrono>

#include "task.h"

int main (int argc, char **argv) {

  // initialise MPI
  MPI_Init(&argc, &argv);

  // Get how many processors there are
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // Get which processor this is
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Get the name of the processor
  char name[MPI_MAX_PROCESSOR_NAME];
  int name_length;
  MPI_Get_processor_name(name, &name_length);

  // Get start time
  auto start = std::chrono::high_resolution_clock::now();

  int iterations = 10;

  // run simulation
  for (int i = 1; i < iterations; i++) {
    task::simulation(i, rank, rank);
  }

  // put in barrier
  MPI_Barrier(MPI_COMM_WORLD);

  // print finished statement
  printf("Finished [%d]!\n", rank);

  // put in barrier to wait for every processor to complete
  MPI_Barrier(MPI_COMM_WORLD);

  // get time at the end
  auto end = std::chrono::high_resolution_clock::now();

  if (rank == 0) {
    // get duration
    std::chrono::duration<double, std::milli> duration = end - start;
    printf("Total time (Parallel): %fms\n", duration.count());
  }

  // Run the same thing again in serial
  if (rank == 0) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
    // run simulation
      for (int j = 1; j < iterations; j++) {
        task::simulation(j, i, rank);
      }
      printf("Finished [%d]!\n", i);
    }
    // get time at the end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    printf("Total time (Serial): %fms\n", duration.count());
  }

  // Final steps before returning
  MPI_Finalize();
  return 0;
}