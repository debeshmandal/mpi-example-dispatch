# MPI Example

This repository is a simple example of how to run jobs in parallel using basic MPI. This is as basic as using MPI gets and the `dispatch-task` relationship is used.

A use-case for this model is when running many molecular simulations in parallel, but changing a small set of parameters, typically a random seed.

At the current time of writing, there is no MPI communication presented but this may be added in the future, for example to demonstrate a simulation where particles or energy are exchanged between parallel systems at different temperatures.

The example is designed to run on Linux systems and has been tested on WSL2 running Ubuntu - hence we imagine that it would work on most Ubuntu systems. The main prerequisites are:

- MPI (either `mpich` or `openmpi`)

On Ubuntu, MPI can be installed using:

```bash
sudo apt-get install mpich
```

To check that the program runs, use:

```bash
make example
```
The example file provides a template for initialising a simple MPI program. Here are the key features:

- Initialise MPI using `MPI_Init`
```c++
MPI_Init(&argc, &argv);
```
- Figure out how many processors are being used
```c++
int size;
MPI_Comm_size(MPI_COMM_WORLD, &size);
```
- Figure out which processor we are using
```c++
int rank;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
```
- Get the processor name (on a PC this would typically just be your machine name)
```c++
char name[MPI_MAX_PROCESSOR_NAME];
int name_length;
MPI_Get_processor_name(name, &name_length);
```
- Finally use `MPI_Finalize` to tidy everything up
```c++
MPI_Finalize();
```