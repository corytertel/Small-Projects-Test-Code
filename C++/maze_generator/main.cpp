#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include "maze.cpp"
#include "maze_algorithm.cpp"
#include "maze_cell.cpp"
#include "maze_wall.cpp"

int main(int argc, char** argv) {
    Maze maze{ 15, 15, new DepthFirstSearch };

    printf("===Maze Generator Test===\n");
    printf("\nDepth First Search:\n");
    printf("{}", maze.to_string());

    maze.set_algorithm(new PrimsAlgorithm);
    maze.regenerate();
    printf("\nPrim's Algorithm\n");
    printf("{}", maze.to_string());

    maze.set_algorithm(new KruskalsAlgorithm);
    maze.regenerate();
    printf("\nKruskal's Algorithm\n");
    printf("{}", maze.to_string());

    return 0;
}

