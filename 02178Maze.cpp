#include <iostream>
#include <queue>

using namespace std;

struct position {
  int r, c;
};
int row, col;
int maze[102][102];

int print() {
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      cout << maze[r][c] << " ";
    }
    cout << endl;
  }
}

int main() {
  // get input
  cin >> row >> col;
  char temp;
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      cin >> temp;
      maze[r][c] = temp - '0';
    }
  }

  // initialize queue
  queue <position> next;
  next.push(position{0,0});
  maze[0][0] = 2;

  // check step by step
  while(!next.empty()) {
    position p = next.front();
    next.pop();

    // stop point
    if(p.r == row && p.c == col)
      break;

    // up
    if (p.r-1 >= 0 && maze[p.r-1][p.c] == 1) {
      maze[p.r-1][p.c] = maze[p.r][p.c] + 1;
      next.push(position{p.r-1, p.c});
    }
      
    // left
    if (p.c-1 >= 0 && maze[p.r][p.c-1] == 1) {
      maze[p.r][p.c-1] = maze[p.r][p.c] + 1;
      next.push(position{p.r, p.c-1});
    }
    
    // down
    if (p.r+1 < row && maze[p.r+1][p.c] == 1) {
      maze[p.r+1][p.c] = maze[p.r][p.c] + 1;
      next.push(position{p.r+1, p.c});
    }
    
    // right
    if (p.c+1 < col && maze[p.r][p.c+1] == 1) {
      maze[p.r][p.c+1] = maze[p.r][p.c] + 1;
      next.push(position{p.r, p.c+1});
    }

    //cout << endl;
    //print();
  }

  cout << maze[row-1][col-1] - 1 << endl;
  
  return 0;
}
