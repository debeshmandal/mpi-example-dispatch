export CC=mpicxx

dispatch: dispatch.cpp task.cpp task.h
	$(CC) -o dispatch dispatch.cpp task.cpp

example: example.cpp task.cpp example.h task.h
	$(CC) -o example example.cpp task.cpp
	mpirun -np 4 ./example

.PHONY: test
test:
	@mpirun -np 4 ./dispatch
	 

.PHONY: clean
clean:
	@rm -f *.o
	@rm -f example
	@rm -f dispatch
	
