#include <iostream>
#include <queue>

using namespace std;

int hei, row, col;
int tomato[102][102][102];
struct position {
  int h, r, c;
};

void print() {
  for(int h = 0; h < hei; h++) {
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++)
	cout << tomato[h][r][c] << " ";
      cout << endl;
    }
    cout << endl << endl;
  }
}

int main() {
  queue<position> next;
  int last = -1;
  
  // get input
  cin >> col >> row >> hei;

  for(int h = 0; h < hei; h++)
    for (int r = 0; r < row; r++)
      for (int c = 0; c < col; c++) {
	cin >> tomato[h][r][c];
	if (tomato[h][r][c] == 1)
	  next.push(position{h,r,c});
      }

  while(!next.empty()) {
    position p = next.front();
    //cout <<  p.h << " " << p.r << " " << p.c << endl;
    next.pop();

    // height up
    if (p.h-1 >= 0 && tomato[p.h-1][p.r][p.c] == 0) {
      last = tomato[p.h-1][p.r][p.c] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h-1, p.r, p.c});
    }
      
    // height down
    if (p.h+1 < hei && tomato[p.h+1][p.r][p.c] == 0) {
      last = tomato[p.h+1][p.r][p.c] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h+1, p.r, p.c});
    }

    // row left
    if (p.r-1 >= 0 && tomato[p.h][p.r-1][p.c] == 0) {
      last = tomato[p.h][p.r-1][p.c] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h, p.r-1, p.c});
    }
    
    // row right
    if (p.r+1 < row && tomato[p.h][p.r+1][p.c] == 0) {
      last = tomato[p.h][p.r+1][p.c] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h, p.r+1, p.c});
    }

    // column front
    if (p.c-1 >= 0 && tomato[p.h][p.r][p.c-1] == 0) {
      last = tomato[p.h][p.r][p.c-1] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h, p.r, p.c-1});
    }

    // column back
    if (p.c+1 < col && tomato[p.h][p.r][p.c+1] == 0) {
      last = tomato[p.h][p.r][p.c+1] = tomato[p.h][p.r][p.c] + 1;
      next.push(position{p.h, p.r, p.c+1});
    }

    //print();
  }

  // print result
  for(int h = 0; h < hei; h++)
    for (int r = 0; r < row; r++)
      for (int c = 0; c < col; c++)
	if (tomato[h][r][c] == 0) {
	  cout << -1 << endl;
	  return 0;
	}
  cout << last-1 << endl;
  
  return 0;
}
