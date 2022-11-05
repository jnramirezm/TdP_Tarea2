FLAGS = -g -Wall

all: main test_Package test_Container test_Container_Solver

main: main.cpp Container_Solver.o Container.o Package.o
	g++ $(FLAGS) -o main main.cpp Container_Solver.o Container.o Package.o

Container_Solver.o: Container_Solver.cpp Container_Solver.h 
	g++ $(FLAGS) -c Container_Solver.cpp

Container.o: Container.cpp  Container.h 
	g++ $(FLAGS) -c Container.cpp

Package.o: Package.cpp Package.h
	g++ $(FLAGS) -c Package.cpp

test_Package: test_Package.cpp Package.o
	g++ $(FLAGS) -o test_Package test_Package.cpp Package.o

test_Container: test_Container.cpp Container.o Package.o
	g++ $(FLAGS) -o test_Container test_Container.cpp Container.o Package.o

test_Container_Solver: test_Container_Solver.cpp Container_Solver.o Container.o Package.o
	g++ $(FLAGS) -o test_Container_Solver test_Container_Solver.cpp Container_Solver.o Container.o Package.o

clear:
	rm -f *.o main test_Container test_Package