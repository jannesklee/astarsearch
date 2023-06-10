# A* Pathfinding Algorithm in C++

This project implements the A* pathfinding algorithm in C++ and uses it to find a path in a graph.

## Requirements

- A C++ compiler supporting C++20 or later
- GNU Make.

## Building the project

To build the project, run:

    make

This will create the executable build/astar. It assumes that a subfolder build
was created. In case it was not run

    mkdir build

## Running the project

To run the project, you first need to have the nodes.csv and edges.csv files in your project root directory. These files define the graph on which the A* algorithm will be executed.

Then, you can run the project with:

    ./build/astar

The output will be a file named path.csv in the project root directory. This file contains the sequence of node IDs representing the path found by the A* algorithm.

## Structure

The project has the following directory structure:

- build
- include
- src
- nodes.csv
- edges.csv
- Makefile

include/: Contains header files.
src/: Contains source files.
nodes.csv: Input file with the graph nodes.
edges.csv: Input file with the graph edges.
Makefile: Used to build the project.


