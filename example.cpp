#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <bits/stdc++.h>

#include "example.h"

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

  // Create the template for a message
  std::string message = "";
  for (int i = 0; i < name_length; i++) {
    message += name[i];
  }
  message += "[" + std::to_string(rank) + "]"; 
  message += "!\n";

  // Let's make rank 0 the main processor and print hello world from it
  // From the others we will print another message
  if (rank == 0) {
    message = "Hello World - " + message;
  } else {
    message = "See ya - " + message;
  }

  // finally print message - we need to use the .c_str method
  // from the string instance for printf
  printf(message.c_str());

  // Final steps before returning
  MPI_Finalize();
  return 0;
}