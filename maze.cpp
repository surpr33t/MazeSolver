  /* 
  maze.cpp
  */

  #include <iostream>
  #include <fstream>
  #include "queue.h"
  #include "maze.h"

  using namespace std;


  Maze::Maze() {
    // Complete this function 
  }
  Maze::~Maze() {
    // Complete this function
    if (file1 != nullptr) {
      for (int i=0; i < row; i++) {
        delete[] file1[i];
      }
      delete[] file1;
      file1 = nullptr; 
    }
  }
  // Intializes the maze from the given file.
  // Expects the appropriate format from the assignment
  // Returns true, if there was an error reading the file,
  // false otherwise
  bool Maze::read_maze(char* filename) {
    // Complete this function
    ifstream ifile (filename);

    if (ifile.fail()) {
      return 1; 
    }
    
    ifile >> row >> col;
    ifile.ignore(); //ignores newline 

    if(ifile.fail()) {
      return 1; 
    }
    
    file1 = new char*[row];
    for (int i=0; i < row; i++) {
      file1[i] = new char[col + 1];
      file1[i][col] = '\0';  // add terminator at end of row
      ifile.getline(file1[i],col+2);
    }

    return 0; 
  }

  // Prints the maze to cout using the format
  // specified in the assignment
  void Maze::print_maze() const {
    cout << row << " " << col << endl; 
    for(int i=0; i < row; i++) {
      cout << file1[i] << endl; 
    }
  }

  //need a function to determine if all char in the maze all valid is periof # or 
  bool Maze::validChar() {
    for (int i=0; i < row; i++) {
      for (int j=0; j < col; j++) {
        if (file1[i][j] != '.' && file1[i][j] != '#' && file1[i][j] != 'S' && file1[i][j] != 'F' && file1[i][j] != '*' && file1[i][j] != '\0') {
          return 1; 
      }
    }
  }
  return 0; 
  }

  //need a function to determine exactly one start and one finish would not be const 
  bool Maze::validSF(){
    int startCnt = 0;
    int finishCnt = 0; 

    for (int i=0; i < row; i++) {
      for (int j=0; j < col; j++) {
        if (file1[i][j] == 'S') {
          startCnt++; 
        }
        if (file1[i][j] == 'F') {
          finishCnt++; 
        }
      }
    }
    return (startCnt != 1 || finishCnt != 1); 
  }

  bool Maze::BFS() {
  Location start; 
  for(int i=0; i < row; i++) {
    for(int j=0; j < col; j++) {
      if (file1[i][j] == 'S') {
        start.row = i;
        start.col= j; 
        break; 
      }
    }
  }
  Location finish; 
  for(int i=0; i < row; i++) {
    for(int j=0; j < col; j++) {
      if (file1[i][j] == 'F') {
        finish.row = i;
        finish.col= j; 
        break; 
      }
    }
  }

  Location** predecessor = new Location*[row]; 
    for (int i=0; i < row; i++) {
      predecessor[i] = new Location[col];
    }
  int** visited = new int*[row]; 
    for (int i=0; i < row; i++) {
      visited[i] = new int[col];
      for (int j=0; j < col; j++) {
        visited[i][j] = 0; 
      }
    }
  //mark the start location as explored
  visited[start.row][start.col] = 1; 
  // add start location to queue
  Queue myQ;
  myQ.add_to_back(start); 
  // while q is not empty do:
  bool found = false; 
  while(!myQ.is_empty()) {
  //   extract the item from the front of queue
    Location item = myQ.remove_from_front(); 
    int r = item.row; 
    int c = item.col; 
    if (r == finish.row && c == finish.col) {
      found = true;
      break; 
    }
    visited[r][c] = 1; 
  //   for each neighbor (i.e., N,W,S, and E) of the extracted location do:
  //     if the neighbor is valid, open, and not yet explored do:
  //       Update any necessary bookkeeping data
  //       add the neighbor to the back of queue
  //N
    if(r -1  >= 0 && file1[r - 1][c] != '#' && visited[r - 1][c] == 0) {
      Location neighbor; 
      neighbor.row = r-1;
      neighbor.col = c; 
      myQ.add_to_back(neighbor);
      predecessor[r-1][c] = item; 
    }
    //W
    if(c - 1 >= 0 && file1[r][c-1] != '#' && visited[r][c - 1] == 0) {
      Location neighbor; 
      neighbor.row = r;
      neighbor.col = c -1; 
      myQ.add_to_back(neighbor);
      predecessor[r][c-1] = item; 
    }
    //S
    if(r + 1 < row && file1[r + 1][c] != '#' && visited[r + 1][c] == 0) {
      Location neighbor; 
      neighbor.row = r+1;
      neighbor.col = c; 
      myQ.add_to_back(neighbor);
      predecessor[r+1][c] = item;
    }
    //E
    if(c + 1 < col && file1[r][c + 1] != '#' && visited[r][c + 1] == 0) {
      Location neighbor; 
      neighbor.row = r;
      neighbor.col = c + 1; 
      myQ.add_to_back(neighbor);
      predecessor[r][c+1] = item; 
    }
  }

  //Retracing your steps 
  if (found){
    Location current = finish; 
    while (!(current.row == start.row && current.col == start.col)) {
    if (file1[current.row][current.col] == '.') {
      file1[current.row][current.col] = '*';
    }
    current = predecessor[current.row][current.col];
  } 
  }
  for (int i=0; i < row; i++) {
    delete[] predecessor[i]; 
    delete[] visited[i];
  }
  delete[] visited; 
  delete[] predecessor;

  return found; 
  }
