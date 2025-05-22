  /*
  maze.cpp
  */

  #include <iostream>
  #include "maze.h"
  using namespace std;


  // main function to read, solve maze, and print result
  int main(int argc, char* argv[]) {
    if(argc < 2)
    {
        cout << "Please provide a maze input file" << endl;
        return 0;
    }
    
    const char* invalid_char_msg = "Error, invalid character.";
    const char* invalid_maze_file_msg = "Invalid maze file.";
    const char* invalid_maze_msg = "Invalid maze start or finish.";
    const char* no_path_msg = "No path could be found!";

    Maze m;
    if (m.read_maze(argv[1])) {
      cout << invalid_maze_file_msg << endl;
        return 0;     // ALWAYS RETURN 0 from this program.
    }
    if (m.validChar()) {
      cout << invalid_char_msg << endl; 
      return 0; 
    }
    if (m.validSF()) {
      cout << invalid_maze_msg << endl; 
      return 0; 
    }
    if (m.BFS() == false) {
      cout << no_path_msg << endl; 
      return 0; 
    }

    m.print_maze();
    
    // Complete the remainder of the program below
    // ALWAYS RETURN 0 from this program.
    return 0;
  }

