/* 
maze.h
*/

#ifndef MAZE_H
#define MAZE_H
#include "location.h"

// Class that stores the maze and performs
// operations on the maze
class Maze {
public:
    Maze();
    ~Maze();
    // Intializes the maze from the given file.
    // Expects the appropriate format from the assignment
    // Returns true, if there was an error reading the file,
    // false otherwise
    bool read_maze(char* filename);
    // Prints the maze to cout using the format
    // specified in the assignment
    void print_maze() const;

    // Add any other desired functions
    bool validChar();
    bool validSF();
    bool BFS(); 


private:
    // Add private data members and private functions here
    int row, col; 
    char** file1; 
    Location start; 
    Location finish; 
};

#endif
